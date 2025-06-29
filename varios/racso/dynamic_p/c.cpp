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
  ll n;
  cin >> n;
  vector<vl> m(n, vl(n));
  for(auto& r: m) 
    for(auto& c: r) cin >> c;
  for (auto r = 0; r < n; ++r) {
    for (auto c = 0; c < n; ++c) {
      ll s = 0;
      if (r) s+=m[r-1][c];
      if (c) s+=m[r][c-1];
      if (r and c) s-=m[r-1][c-1];
      m[r][c] += s;
    }
  }

  ll ans = m[0][0];
  auto f = [&](int r, int c, int rp, int cp) {
    ll xd = m[r][c];
    if (rp) xd-=m[rp-1][c];
    if (cp) xd-=m[r][cp-1];
    if (rp and cp) xd+=m[rp-1][cp-1];
    return xd;
  };
  for (auto r = 0; r < n; ++r) {
    for (auto l = 0; l <= r; ++l) {
      ll lans = f(0,r,0,l);
      ll v = 0;
      for (auto row = 0; row < n; ++row) {
        v += f(row, r, row, l);
        if (v > lans)lans=v;
        if (v < 0) v = 0;
      }
      ans = max(ans, lans);
    }
  }
  cout << ans << '\n';
  
}


