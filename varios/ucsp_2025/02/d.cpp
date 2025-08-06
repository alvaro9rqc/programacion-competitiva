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
  int n, k; cin >> n >>k;
  vl a(n);
  for(auto& e: a) cin >> e;  
  vector<vl> m(n,vl(n));
  rep(i, 0, n) {
    map<ll,ll> fr;
    rep(j, i, n) {
      ll ma = -1, fma = -1;
      ll mi = (ll)1e10, fmi = 110;
      fr[a[j]]++;
      for(auto& [v, f]: fr) {
        if (f > fma or (f == fma and v > ma)) ma = v, fma = f;
        if (f < fmi or (f == fmi and v < mi)) mi = v, fmi = f;
      }
      m[i][j] = ma - mi;
    }
  }
  ll inf = 1e14;
  vector<vl> dp(k+1, vl(n, -inf));
  for (auto i = 0; i < n; ++i) {
    dp[1][i] = m[i].back();
  }
  for (auto ki = 2; ki <= k; ++ki) {
    for (auto i = n-1; i >= 0; --i) {
      dp[ki][i] = max(dp[ki][i], m[i].back());
      for (auto x = i; x < n-1; ++x) {
        dp[ki][i] = max(dp[ki][i], m[i][x] +dp[ki-1][x+1]);
      }
    }
  }
  cout << dp[k][0] << '\n';
}



