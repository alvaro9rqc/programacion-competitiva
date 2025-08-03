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
  cin.exceptions(cin.failbit);
  //  s: dp[l][r] = mayor cantidad de puntaje que se puede obtener
  //  r: dp[l][r] = max(al - dp[l+1][r], ar - dp[l][r])
  //  b: dp[l][r] = a[l] si l = r
  //  o: dp[0][n-1]
  int n; cin >> n;
  vector<vl> dp(n, vl(n));
  vi a(n); 
  for(auto& e: a) cin >> e;
  for (auto i = 0; i < n; ++i) dp[i][i] = a[i];
  for (auto d = 1; d < n; ++d) {
    for (auto l = 0, r = d; r < n; ++l,++r) {
      dp[l][r] = max(a[l] - dp[l+1][r], a[r] - dp[l][r-1]);
    }
  }
  cout << dp[0][n-1] <<'\n';
}


