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
    ll x, y, k; cin >> x >> y >> k;
    ll n = ll(1e12);
    for (auto i = 0ll; i < x; i++) {
      n -= n / y;
    }
    if (k > n) {
      cout << -1 <<'\n';
    } else {
      for (auto i = 0ll; i < x; i++) {
        k += (k-1)/(y-1);
      }
      cout << k <<'\n';
    }
  }
}

