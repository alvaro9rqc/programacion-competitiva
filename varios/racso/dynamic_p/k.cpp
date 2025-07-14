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
  ll n; cin >> n;
  vector<vi> memo(n+3, vi(n+3, 1)) ;
  int mod = 1e9+7;
  for (int i = 2; i <= n; ++i) {
    for (int j = 2; j < i; ++j) {
      memo[i][j] = (memo[i-j][min(i-j, j)]%mod + memo[i][j-1]%mod)%mod;
    }
    memo[i][i] += memo[i][i-1];
  }
  cout  << memo[n][n];
}


