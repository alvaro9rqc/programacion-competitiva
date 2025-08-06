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
  vl a(n); 
  for (auto i = 0; i < n; ++i) cin >> a[i], a[i] += (i?a[i-1]:0);
  ll inf = (ll) 4e12;
  vector<vl> dp(n, vl(n,inf));
  auto sq = [&a](int j, int i) { return a[i] - (j?a[j-1]:0); };
  for (auto i = 0; i < n; ++i) dp[i][i] = 0;
  for (auto d = 1; d < n; ++d) {
    for (auto i = 0, j = d; j < n; ++i,++j) {
      for (auto x = i; x < j; ++x) {
        dp[i][j] = min(dp[i][j], dp[i][x] + sq(i,x) + dp[x+1][j] + sq(x+1,j));
      }
    }
  }
  cout << dp.front().back() <<'\n';
}


