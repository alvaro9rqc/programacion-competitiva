#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
#define dbg(x) cerr << #x << " = " << (x) << endl;
#define raya cerr << " ==================== " << endl;
#define rep(i, a, b) for (auto i = a; i < (b); ++i)
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)

#include <bits/extc++.h>
// To use most b i t s rather than j u s t the lowest ones :
struct chash { // large odd number for C
  uint64_t C = ll(4e18 * acos(0)) | 71;
  ll operator()(ll x) const { return __builtin_bswap64(x*C); }
};
// __gnu_pbds::gp_hash_table<ll,int,chash> h({},{},{},{},{1<<16});
using h_m = __gnu_pbds::gp_hash_table<ll,ll,chash>;

vector<vector<pair<bool,int>>> adj;

vector<vi> vis;

vl pos, del;

vector<tuple<ll,bool,int>> que;

int n;ll k;

bool lef=0,rig=1;

void f1(int i, int j, int d, int m) {
  h_m ump;
  ump[del[i]]=i;
  i+=d;
  ll x =0;
  for (;i!=j;i+=d) {
    x=(x+abs(pos[i]-pos[i-d]))%k;
    auto y = (del[i]+x)%k;
    auto it = ump.find(y);
    if(it!=ump.end()) {
      auto [p,id]=*it;
      if(id!=i) adj[i].emplace_back(m,id);
    }
    ump[y]=i;
  } 
}

int nu=0,pe=1,fr=2;
int dp(int di, int u) {
  if (vis[di][u]!=nu) return vis[di][u];
  auto& r = vis[di][u];
  r=pe;
  ll c=0;
  for(auto& [d2,v]: adj[u]) {
    if(d2!=di){
      c=1;
      if(dp(d2,v)!=pe)r=fr;
    }
  }
  if(!c)r=fr;
  return r;
}

void solve() {
  cin>>n>>k;
  adj.assign(n, vector<pair<bool,int>>());
  vis.assign(2,vi(n,nu));
  pos.resize(n);
  del.resize(n);
  for(auto& i: pos) cin >> i; 
  for(auto& i: del) cin >> i; 
  f1(0,n ,1 ,rig);
  f1(n-1,-1,-1,lef);
  for (auto i = 0; i < n; i++) {
    for (auto j = 0; j < 2; j++) dp(j,i)
      // ,cerr<<dp(j,i)<<' '
      ;
    // cerr<<'\n';
  }
  // dbg(sz(adj[0]));
  // dbg(adj[0][0].first);
  // dbg(adj[0][0].second);
  // raya;
  int q;cin>>q;
  que.clear();
  for (auto i = 0; i < q; i++) {
    ll a;cin>>a;
    que.emplace_back(a,0,i);
  }
  for (auto i = 0; i < n; i++) {
    que.emplace_back(pos[i],1,i);
  }
  sort(all(que));
  vl ans(q);
  while(get<1>(que.back())==0) {
    ans[get<2>(que.back())]=1;
    que.pop_back();
  }
  h_m ump;
  ll x=0;
  ump[del[get<2>(que.back())]]=get<2>(que.back());
  // dbg(ump[0]);
  for (auto i = sz(que)-2; i >=0; i--) {
    auto [pj,nqj,idj]=que[i+1];
    auto [pi,nqi,idi]=que[i];
    x=(x+abs(pj-pi))%k;
    if(nqi) {
      auto y = (del[idi]+x)%k;
      ump[y]=idi;
    } else {
      auto it = ump.find(x);
      if(it!=ump.end()) {
        // dbg(idi);
        // dbg(pi);
        // dbg(ump[x]);
        // dbg(dp(0,1));
        ans[idi]=(dp(lef,int(ump[x]))==fr);
      } else ans[idi]=1;
    }
  }
  for(auto& i: ans) cout<<(i?"yes":"no")<<'\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt=1;
  cin>>tt;
  while(tt--) {
    solve();
  }
}

