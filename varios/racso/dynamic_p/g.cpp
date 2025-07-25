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


int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  ll n, W; cin >> n >> W;
  vl v(n);
  vl w(n);
  ll INF = 1e15;
  for (ll i = 0; i < n; ++i) {
    cin >> v[i] >> w[i];
  }
  ll V = 101*n;
  vl dp(V, INF);
  dp[0] = 0;
  for (auto i = 0; i < n; ++i) {
    for (ll val = V; val >= v[i]; --val) {
      dp[val] = min(dp[val], dp[val - v[i]] + w[i]);
    }
  }
  ll ans = 0;
  for (ll val = 0; val < V; ++val) {
    if (dp[val] <= W) ans = val;
  }
  cout << ans <<'\n';
}


