#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
#define endl '\n'
#define dbg(x) cerr << #x << " = " << (x) << endl;
#define raya cerr << " ==================== " << endl;
#define rep(i, a, b) for (auto i = a; i < (b); ++i)
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n; cin >> n;
  vl dp(n+1);
  dp[1] = 0;
  for (auto i = 2; i < n+1; ++i) {
    ll ans = i-1;
    if (i % 2 == 0) ans = min(ans, 1 + dp[i/2]);
    if (i % 3 == 0) ans = min(ans, 1 + dp[i/3]);
    //dbg(i);
    //dbg(ans);
    ans = min (ans, 1 + dp[i-1]);
    //dbg(ans);
    //dbg(dp[n-1]);
    dp[i] = ans;
    //dbg(dp[i]);
  }
  //for (auto i = 0; i < 10; ++i) cout << dp[i] << ' ';
  //cout << '\n';
  cout << dp[n] << '\n';
}


