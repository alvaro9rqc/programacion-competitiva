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
  int n,m;
  cin >> n >> m;
  int inf = 3e5;
  vector<vi> dp(n, vi(1<<n, inf));
  vector<vi> mat(n,vi(n,inf));
  for (auto i = 0; i < m; ++i) {
    int x, y, w; cin >> x >> y >> w;
    mat[x][y] = min(mat[x][y], w);
  }

  for (auto i = 0; i < n; ++i) dp[i][0] = mat[i][n-1];
  for (auto N = 1; N < (1<<(n-1)); ++N) {
    for (auto v = 0; v < n; ++v) {
      if ((1<<v)&N) continue;
      for (auto k = 0; k < n-1; ++k) {
        if(not (1<<k&N)) continue;
        //cout <<": " << dp[v][N] <<' ' <<v <<' ' << k <<' '<<N <<'\n';
        dp[v][N] = min(dp[v][N], 
            mat[v][k]+dp[k][N^(1<<k)]
            );
        //cout << dp[v][N] <<' ' <<v <<' ' << k <<' '<<N <<' '<<mat[v][k] <<'\n';
      }
    }
  }
  auto ans =dp[n-1][(1<<(n-1))-1];
  cout << (ans == inf ? -1:ans) <<'\n';

}


