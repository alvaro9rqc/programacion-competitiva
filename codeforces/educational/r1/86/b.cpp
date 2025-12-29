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
  vi a={0},b={0};
  for (auto i = 1; i < 29; i++) {
    if (i&1) {
      a.emplace_back(a.back()+(1<<(i-1)));
      b.emplace_back(b.back());
    } else {
      a.emplace_back(a.back());
      b.emplace_back(b.back()+(1<<(i-1)));
    }
  }
  int tt; cin >> tt;
  while(tt--) {
    int w, d; cin >> w >> d;
    if (d<w)swap(w,d);
    int ans = 0;
    for (auto i = 0; i < sz(a); i++) {
      auto l = a[i];
      auto r = b[i];
      if (r < l) swap(l,r);
      if (l <= w and r <= d) ans=i;
      else break;
    }
    cout << ans<<'\n';
  }
}

