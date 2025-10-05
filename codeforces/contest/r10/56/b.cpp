#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
#define dbg(x) cerr << #x << " = " << (x) << endl;
#define raya cerr << " ==================== " << endl;
#define rep(i, a, b) for (auto i = a; i < (b); ++i)
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt;cin >> tt;
  while(tt--) {
    int n; cin >> n;
    int k; cin >> k;
    if (k == n*n-1) {
      cout << "NO\n";
      continue;
    }
    vector<string> grid(n, string(n, 'D'));
    for(auto& c: grid.back()) c = 'R';
    grid.back().back() = 'L';
    for (auto r = 0; r < n and k; r++) {
      for (auto c = 0; c < n and k; c++) {
        --k;
        grid[r][c]='L';
      }
    }
    cout << "YES\n";
    for(auto& s: grid) cout << s <<'\n';
  }
}

