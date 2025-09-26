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
  vl dp(n);
  vl h(n);
  for(auto& i: h) cin >> i;
  dp.back() = 0;
  for (auto i = n-2; i >= 0; --i) {
    ll ans = h.back() - h[i];
    if (ans < 0) ans=-ans;
    for (auto j = i+1; j < n; ++j) ans = min(ans, ll(abs(h[i]-h[j]) + dp[j]));
    dp[i] = ans;
  }
  cout << dp[0] << '\n';
}


