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
using h_m = __gnu_pbds::gp_hash_table<int,int,chash>;

void solve() {
  int n;cin>>n;
  vector<ii> par(n);
  set<int>setx,sety;
  for(auto& [a,b]: par) cin >> a>>b,setx.emplace(a), sety.emplace(b);
  h_m xid,yid;
  for(auto [it,i]=tuple{setx.begin(),0}; it!=setx.end();++it,++i) 
    xid[*it]=i;
  for(auto [it,i]=tuple{sety.begin(),0}; it!=sety.end();++it,++i) 
    yid[*it]=i;
  vi hx(sz(setx),-1), lx(sz(setx),n+100);
  vi hcx(sz(setx),-1), lcx(sz(setx),n+100);
  for(auto& [x,y]: par) {
    hx[xid[x]]=max(hx[xid[x]], yid[y]);
    lx[xid[x]]=min(lx[xid[x]], yid[y]);
  }
  int nx = sz(setx);
  for (auto i = 1,h=hx[0],l=lx[0]; i < nx; i++) {
    hcx[i-1]=h;
    h = max(hx[i],h);
    lcx[i-1]=l;
    l = min(lx[i],l);
  }
  ll ans = 0;
  // for(auto& i: lcx) cout<<i <<' ';
  // cout<<'\n';
  for (auto i = nx-2,h=hx[nx-1],l=lx[nx-1]; i >= 0; i--) {
    ans+=max(0, 
             min(hcx[i], h)-max(lcx[i],l)
             );
    h=max(hx[i],h);
    l=min(lx[i],l);
  }
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

