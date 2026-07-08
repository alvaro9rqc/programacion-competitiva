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

void solve() {
  int n;cin>>n;
  vl val(n); for(auto& i: val) cin >> i;  
  vector<vi> adj(n);
  for (auto i = 0; i < n-1; i++) {
    int u, v;cin>>u>>v;
    --u,--v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }
  int lo = int(log2(n)+3);
  ll inf = 1e18;
  vector<vl> dp(n,
                vl(lo,inf));
  ll ans = inf;
  auto dfs = [&](auto&& self, int u, int p) ->void {
    auto& d = dp[u];
    //always
    for (auto l = 0; l < lo; l++) 
      d[l]=(l+1)*val[u];
    //chil
    for(auto& v: adj[u]) {
      if(v==p)continue;
      self(self,v,u);
      for (auto l = 0; l < lo; l++) 
        d[l]+=dp[v][l];
    }
    //ans
    if(u==0) for(auto& i: d) ans=min(ans,i);
    //ever
    vl su(lo,inf),pr(lo,inf);
    for (auto l = 1; l < lo; l++) pr[l]=min(pr[l-1],d[l-1]);
    for (auto l = lo-2; l >= 0; l--) su[l]=min(su[l+1],d[l+1]);
    for (auto l = 0; l < lo; l++) d[l]=min(pr[l],su[l]);
  };
  dfs(dfs,0,0);
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

