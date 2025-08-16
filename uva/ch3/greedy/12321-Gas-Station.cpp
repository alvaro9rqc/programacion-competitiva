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
  ll l, g; 
  while(1) {
    cin >> l >> g;
    if (l == 0 and g == 0) break;
    vector<pair<ll,ll>> par;
    for (ll i = 0; i < g; ++i) {
      ll x, r; cin >> x >> r;
      par.emplace_back(x-r, x+r);
    }
    sort(all(par));
    ll r = 0;
    int idx = 0;
    int c = 0;
    while(r < l) {
      bool sel = 0;
      ll piv = r;
      for (; idx < g and par[idx].first <= r; ++idx) {
        if (par[idx].second > piv) {
          piv = par[idx].second;
          sel=1;
        }
      }
      if (sel) {
        r = piv;
        ++c;
      } else {
        break;
      }
    } 
    if (r < l) cout << -1 << '\n';
    else cout << g - c << '\n';
  }
}


