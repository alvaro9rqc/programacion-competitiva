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
  int n, g;
  while(cin >> n >> g) {
    vi fal;
    int pp = 0;
    for (auto i = 0; i < n; ++i) {
      int x, y; cin >> x >> y;
      x = y - x;
      if (x >= 0) fal.emplace_back(x);
      if (x == 0) ++pp;
      else if ( x < 0 ) pp+=3; 
    }
    sort(all(fal));
    int ans = 0;
    for(auto& f: fal) {
      if (g > f) {
        if (f == 0) --g, ans+=2; 
        else g -= f+1, ans+=3;
      } else if (g == f) {
        if (g == 0) { continue; }
        g -= f;
        ++ans;
      } else break;
    }
    cout << ans+pp << '\n';
  }
}


