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
    ll l, r, g; cin >> l >> r >> g;
    l = l / g + (l%g?1:0);
    r = r / g;
    bool can = 0;
    for(ll d = r - l; d >= 0; --d) {
      for(ll i = l; i + d <= r; ++i) {
        if (gcd(i, i+d) == 1) {
          can = 1;
          cout << i*g <<' '<< (i+d)*g<<'\n';
          break;
        }
      }
      if (can) break;
    }
    if (not can) cout << "-1 -1\n";
  }
}

