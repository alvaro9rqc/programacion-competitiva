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
  int cases = 0;
  while(cases++ < tt) {
    int n, m; cin >> n >> m;
    ll k ; cin >> k;
    vector<vl> gr(n, vl(m));
    for(auto& r: gr) 
      for(auto& c: r) cin >> c;
    for(auto& r: gr) {
      for (auto i = 1; i < m; ++i) r[i]+=r[i-1];
    }
    //for(auto& r: gr) {
    //  for(auto& c: r) cout << c << ' ';
    //  cout << '\n';
    //}
    auto sum = [&gr] (int row, int l, int r) {
      return gr[row][r] - (l?gr[row][l-1]:0);
    };
    ll s=0, p=ll(1e11);
    for (auto l = 0; l < m; ++l) {
      for (auto r = l; r < m; ++r) {
        ll lp = 0;
        for (auto i = 0, j = 0; i < n and j < n; ++i) {
          for (; j < n; ++j) {
            if (lp + sum(j, l, r) <= k) lp+=sum(j,l,r);
            else break;
          }
          ll sp = (r-l+1)*(j-i);
          if (lp <= k) {
            if (sp > s) s=sp, p = lp;
            else if (sp == s) p = min(p, lp);
          }
          //cerr << l <<' '<<r<<' '<<i<<' '<<j<<'\n';
          //dbg(lp);
          //dbg(sum(i,l,r));
          //raya;
          if (j == i) j = i+1;
          else lp -= sum(i, l, r);
        }
      }
    }
    cout << "Case #" << cases <<  ": " << s << " " << p << '\n';
  }
}


