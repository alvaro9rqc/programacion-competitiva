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
  int n, m;
  cin >> n >> m;
  vector<vi> gr(n,vector<int>(m));
  auto dp = gr;
  for(auto& r: gr) 
    for(auto& c: r) cin >> c;
  dp[n-1][m-1] = 1;
  int mod = int(1e9+7);
  for (auto r = n-1; r >= 0; --r) {
    for (auto c = m-1; c >= 0; --c) {
      int ans = 0;
      int d = gr[r][c];
      if (r+d < n) ans+= dp[r+d][c];
      ans%= mod;
      if (c+d < m) ans+= dp[r][c+d];
      ans%= mod;
      dp[r][c] += ans;
      dp[r][c] %= mod;
    }
  }
  cout << dp[0][0] << '\n';
}


