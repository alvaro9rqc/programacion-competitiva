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
  int tt;cin>>tt;
  while(tt--){
    int n;cin>>n;
    vector<double> crr(n), prr(n),dp(n);
    for (auto i = 0; i < n; i++) {
      cin>>crr[i]>>prr[i];
    }
    dp.back()=crr.back();
    for (auto i = n-2; i >= 0; i--) {
      dp[i]=max(
        crr[i]+dp[i+1]*((100-prr[i])/100),
        dp[i+1]
      );
    }
    printf("%.8lf\n",dp[0]);
    // cout<<dp[0]<<'\n';
  }
}

