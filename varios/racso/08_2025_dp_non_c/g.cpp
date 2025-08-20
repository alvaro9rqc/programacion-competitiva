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
  ll mod = ll(1e9+7);
  int n, k; cin >> n>>k;
  vl dp(n);
  dp.back() = 1;
  for (auto i = n-2; i >= 0; --i) {
    ll ans = 0;
    for (auto j = 0; i + j < n and j <= k; ++j) {
      ans+=dp[i+j];
      ans%=mod;
    }
    dp[i] = ans;
  }
  cout << dp[0] <<'\n';
}


