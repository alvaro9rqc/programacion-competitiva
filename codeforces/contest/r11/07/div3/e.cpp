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

vector<vl> adj;
vector<bool> sq;
vl nod;
ll root = 0;

bool isq(ll x) {
  if(x==1) return 1;
  ll s = ll(floor(sqrt(x)));
  for (ll i = s-10; i < s+10; i++) 
    if(i*i==x) return 1;
  return 0;
}

ll son(ll u, ll p) {
  nod[u]=1;
  for(auto& v: adj[u]) {
    if(v==p)continue;
    nod[u]+=son(v,u);
  }
  return nod[u];
}

ll dfs(ll u, ll p) {
  ll ans = 0;
  vl t = {nod[root]-nod[u]};
  for(auto& v: adj[u]) {
    if(v==p) continue;
    t.emplace_back(nod[v]);
    ans+=dfs(v,u);
  }
  if(!sq[u]) return ans;
  //co
  dbg(u);
  dbg(ans);
  dbg(nod[u]);
  for(auto& i: t) cout<<i<<' ';
  cout<<'\n';
  //co
  ll ac = t[0];
  vl t2=t;
  for (auto i = 1; i < sz(t); i++) {
    auto xd = ac;
    ans+=ac*t[i],ac+=t[i];
    t[i]=xd*t[i]+t[i-1];
  }
  dbg(ans);
  for (auto i = 2; i < sz(t2); i++) 
    ans+=t2[i]*t[i-1];
  dbg(ans);
  return ans;
}

void solve() {
  int n;cin>>n;
  sq.assign(n,0);
  adj.assign(n,vl());
  nod.assign(n,0);
  for (auto i = 0; i < n; i++) {
    ll x;cin>>x;
    sq[i]=isq(x);
  }
  for (auto i = 0; i < n-1; i++) {
    ll u,v;cin>>u>>v;
    --u,--v;
    ++nod[u];
    ++nod[v];
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }
  for (auto i = 0; i < n; i++) 
    if(nod[i]==1){root=i;break;}
  fill(all(nod),0);
  son(root,root);
  dbg(root);
  dbg(nod[root]);
  // ans
  ll ans = dfs(root,root);
  cout<<ans<<'\n';
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

