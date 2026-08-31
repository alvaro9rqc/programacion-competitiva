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
  ll mod = 1e9+7;
  while(tt--) {
    int n;cin>>n;
    vi val(n); for(auto& i: val) cin>>i;
    vector<vl>dp(n, vl(n+1, 1));
    //i, c
    for (auto i = n-2; i >= 0; i--) {
      for (auto c = 1; c < n+1; c++) {
        for (auto j = i+1; j < n; j++) {
          if (val[j]>= val[i]) dp[i][c]+=dp[j][max(c,val[j])];
          else 
            if (val[i]>=c)dp[i][c]+=dp[j][c];
          dp[i][c]%=mod;
        }
      }
    }
    ll ans = 1;
    for (auto i = 0; i < n; i++) 
      ans+=dp[i][val[i]],ans%=mod;
    cout << ans <<'\n';
  }
}

