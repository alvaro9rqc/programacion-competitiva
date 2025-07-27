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
  int tt; cin >> tt;
  while(tt--) {
    int n; cin >> n;
    vi a(n);
    for(auto& e: a) cin >> e;
    string ans;
    int l = 0, r = n-1;
    bool dis = 0;
    while(l <= r) {
      ll dr = (int)(abs(a[r] - n));
      ll dl = (int)(abs(a[l] - n));
      if (dis) {
        if (dr > dl) {
          ans.push_back('R');
          --r;
        } else {
          ans.push_back('L');
          ++l;
        }
      } else {
        if (dr > dl) {
          ans.push_back('L');
          ++l;
        } else {
          ans.push_back('R');
          --r;
        }
      }
      dis = not dis;
    }
    cout << ans << '\n';
  }
}


