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
    int n; cin >> n;
    set<int> s;
    int m = int(1e7);
    vector<ii> ans;
    for (auto i = 0; i < n; i++) {
      int x; cin >> x;
      if (x < m) {
        s.insert(x);
        m = x;
      } else {
        auto xd = *s.begin();
        for (auto it = s.begin(); it != s.end(); ) {
          if (*it < x) {
            ans.emplace_back(x, *it);
            it=s.erase(it);
          }
          else break;
        }
        s.insert(xd);
      }
    }
    if (sz(s) == 1) {
      cout << "yes"<<'\n';
      for(auto& [u,v]: ans) cout << u << ' '<<v<<'\n';
    } else cout << "no\n";
  }
}

