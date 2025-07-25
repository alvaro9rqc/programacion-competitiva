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
  ll n; cin >> n;
  ++n;
  vl a(n);
  cin >> a.front();
  for (ll i = 1; i < n-1; ++i) {
    cin >> a[i] >> a[i];
  }
  cin >> a.back();
  vector<vl> dp(n, vl(n));
  //for(auto& e: a) cout << e << ' ';
  //cout << '\n';
  
  for (ll d = 2; d < n; ++d) {
    ll j = 0;
    for (ll i = d; i < n; ++i, ++j) {
      dp[j][i] = a[i]*a[j]*a[j+1] + dp[j][j+1]+dp[j+1][i];
      //cerr << dp[j][i] << '\n';
      for (ll k = j+1; k < i; ++k) {
        dp[j][i] = min(dp[j][i], a[i]*a[j]*a[k] + dp[j][k]+dp[k][i]);
      }
    }
  }
  cout << dp[0][n-1];
}


