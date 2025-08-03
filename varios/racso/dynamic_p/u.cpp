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
  // pre: a ordenado desce
  // dp[k] la jugada óptima de un jugador con k piedras
  // dp[k] = for each ai: 
  //  dp[k] = 1 si dp[k-ai] = 0 al primero
  //  dp[k] = 0 si: dp[k-ai] = 1 por todos los ai
  // base: si la primera piedra no alcanza pierdes -> 0
  int n, k; cin >> n >> k;
  vi a(n);
  sort(a.begin(), a.end());
  for(auto& e: a) cin >> e;
  vector<bool> dp(k+1);
  for (auto i = a[0]; i <= k; ++i) {
    for (auto j = 0; j < n; ++j) {
      if (i - a[j] < 0) break;
      if (not dp[i- a[j]]) {
        dp[i] = 1;
        break;
      }
    }
  }
  cout << (dp[k]?"First":"Second") <<'\n';
}


