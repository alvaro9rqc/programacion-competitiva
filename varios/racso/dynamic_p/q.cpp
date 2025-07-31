#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
#define endl '\n'
#define dbg(x) cerr << #x << " = " << (x) << endl;
#define raya cerr << " ==================== " << endl;
#define FOR(i, a, b) for (auto i = a; i < (b); ++i)
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  while(cin>>n) {
    vi a(n);
    cin >> a.front();
    for (auto i = 1; i < n; ++i) {
      cin >> a[i];
      a[i] += a[i-1];
    }
    auto sum = [&a] (int l, int r) {
      if (r < l) return 0;
      if (l == 0) return a[r];
      return a[r] - a[l-1];
    };
    vector<vi> dp(n,vi(n));
    for (auto l = 1; l < n; ++l) {
      for (auto i = 0, j=l; j < n; ++i,++j) {
        int ans = 1e9;
        ans = min(ans, sum(i+1, j) + dp[i+1][j]);
        ans = min(ans, sum(i, j-1) + dp[i][j-1]);
        //cout << ans << '\n';
        for (auto k = i+1; k < j; ++k) {
          ans = min(ans, 
              sum(i,k-1) + dp[i][k-1] + sum(k+1, j) + dp[k+1][j]
              );
        }
        dp[i][j] = ans;
      }
    }
    cout << dp[0][n-1] << '\n';
  }
}


