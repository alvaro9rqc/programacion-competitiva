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

vector<vl> cof;
ll mod = 998244353;



void solve() {
  ll n,k;cin>>n>>k;
  vl val(n); for(auto& i: val) cin >> i;

  vector<vl> dp(k+1,vl(n+1)), ex(15,vl(n));
  for (auto i = 0; i < n; i++) {
    ll r = 1;
    for (auto e = 0; e < 15; e++) ex[e][i]=r,r=(r*val[i])%mod;
  }
  // dbg(ex[3][0]);
  for (auto i = n-1; i >= 0; i--) {
    for (auto d = 0; d < k+1; d++) {
      auto& ans = dp[d][i];
      for (auto j = 0,e=sz(cof[d])-1; j < sz(cof[d]); j++,--e) {
        ll r=cof[d][j]*ex[e][i]%mod*dp[j][i+1]%mod;
        ans=(ans+r)%mod;
      }
      ans=(ans+ex[d][i])%mod;
    }
  }
  // dbg(dp[0][0]);
  ll ans = 0;
  for (auto i = 0; i < n; i++) ans=(ans+dp[k][i])%mod;
  cout<<ans<<'\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  for (auto i = 0, nf=1; i < 11; nf*=++i) {
    cof.emplace_back();
    ll bf=1,cf=nf;
    int j=0;
    while(1){
      cof[i].emplace_back(nf/(bf*cf));
      if(j==i)break;
      cf/=(i-j);
      bf*=++j;
    }
  }
  int tt=1;
  // cin>>tt;
  while(tt--) {
    solve();
  }
}

