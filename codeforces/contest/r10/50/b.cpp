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
  int tt; cin >> tt;
  while(tt--) {
    int n, m; ll x, y;
    cin >> n >> m >> x >> y;
    for (auto i = 0; i < n; i++) {
      ll a; cin >> a;
    }
    for (auto i = 0; i < m; i++) {
      ll a; cin >> a;
    }
    cout << (n+m) <<'\n';
  }
}

