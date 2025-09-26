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
  int tt; cin >> tt;
  while(tt--) {
    int n; cin >> n;
    vi a(n), b(n);
    for(auto& e: a) cin >> e;
    for(auto& e: b) cin >> e;
    if (a.back() == b.back()) {
      cout << n << '\n';
    } else if (a[n-2] == b[n-2] or a[n-1] == a[n-2] or b[n-2] == b[n-1]) {
      cout << n-1 << '\n';
    } else {
      set<int> s;
      bool fl = 1;
      for (auto i = n-3; i >= 0; --i) {
        s.insert(a[i+2]);
        s.insert(b[i+2]);
        if (s.count(a[i]) or s.count(b[i]) or a[i] == a[i+1] or b[i] == b[i+1] or a[i] == b[i]) {
          cout << i + 1 << '\n';
          fl = 0;
          break;
        }
      }
      if (fl)
      cout << 0 << '\n';
    }
  }
}


