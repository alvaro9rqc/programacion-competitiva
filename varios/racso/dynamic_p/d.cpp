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
  vector<vector<vl>> c(n, vector<vl>(n, vl(n)));
  for(auto& m: c) 
    for (auto i = 0; i < n; ++i) {
      for (auto j = 0; j < n; ++j) {
        cin >> m[i][j];
        if (i) m[i][j] += m[i-1][j];
        if (j) m[i][j] += m[i][j-1];
        if(i and j) m[i][j] -= m[i-1][j-1];
      }
    }
  ll ans = c[0][0][0];
  auto f = [&c](int i, int xp,  int x, int yp, int y) {
    ll a = c[i][y][x];
    if (yp) a -= c[i][yp-1][x];
    if (xp) a -= c[i][y][xp-1];
    if (yp and xp) a+=c[i][yp-1][xp-1];
    return a;
  };
  for (auto x = 0; x < n; ++x) {
    for (auto xp = 0; xp <= x; ++xp) {
      for (auto y = 0; y < n; ++y) {
        for (auto yp = 0; yp <= y; ++yp) {
          ll lans = f(0, xp, x, yp, y);
          ll v = 0;
          for (auto i = 0; i < n; ++i) {
            v += f(i, xp, x, yp, y);
            if (v > lans) lans = v;
            if (v < 0) v = 0;
          }
          ans = max(lans, ans);
        }
      }
    }
  }
  cout << ans << '\n';
}


