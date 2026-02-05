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

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt; cin >> tt;
  while(tt--) {
    ll n,k; cin >> n >> k;
    ll xd = 0;
    cin>>xd;
    vl val={xd},rep={1}, acs={xd};
    for (auto i = 1; i < n; i++) {
      ll x; cin >>x;
      if (val.back()<x) {
        xd+=x;
        val.emplace_back(x);
        acs.emplace_back(acs.back()+xd);
        rep.emplace_back(1);
      } else ++rep.back();
    }
    //k = min(xd,k);
    const ll inf = 1e17;
    vector<vector<vl>> dp(k+1, vector<vl>(k+1, vl(sz(val),-inf)));
    for (auto i = 0; i <= val[0]; i++) 
      dp[i][i][0]=rep[0]*i;
    // for (auto i = val[0]+1; i <= k; i++) 
    //   dp[val[0]][i][0]=dp[val[0]][val[0]][0];
    for(auto& i: val) cout<<i<<' ';
    cout<<'\n';
    for (auto i = 1; i < sz(val); i++) {
      dp[0][0][i]=0;
      for (auto s = 1ll; s <= min(acs[i],k); s++) {
        for (auto m = s/(i+1)+(s%(i+1)?1:0); m <= min(val[i],s); m++) {
          auto& ans=dp[s][m][i];
          dbg(s);
          dbg(m);
          dbg(i);
          dbg(dp[s-m][min({s-m,acs[i-1], k,m,val[i-1]})][i-1]);
          dbg(min({s-m,acs[i-1], k,m,val[i-1]}));
          dbg(rep[i]*m);
          dbg(dp[s][m][i-1]);
          dbg(dp[s][m-1][i]);
          ans=max(ans, rep[i]*m+dp[s-m][min({s-m,acs[i-1], k,m,val[i-1]})][i-1]);
          ans=max(ans, rep[i]*m+dp[s][m][i-1]);
          ans=max(ans, dp[s][m-1][i]);
          dbg(ans);
        }
        // for (auto m = min(val[i],s)+1; m <= k; m++) 
        //   dp[s][m][i]=dp[s][min(val[i],s)][i];
      }
    }
    ll ans = 0;
    xd = min(k,xd);
    int item = sz(val)-1;
    for (auto i = 0ll; i <=xd; i++) {
      for (auto j = 0ll; j <= min(i,val[item]); j++) 
        ans=max(ans, dp[i][j].back());
    }
    cout<<ans<<'\n';
  }

}


