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
    int m; cin >> m;
    vector<ii> par;
    while(1) {
      int a, b; cin >> a >> b;
      if (a == 0 and b == 0) break;
      par.emplace_back(a,b);
    }
    sort(all(par));
    bool can = 1;
    bool hay = 0;
    int r = 0;
    int xd = 0;
    vi ans;
    int idx = -1;
    for (auto i = 0; i < sz(par); ++i) {
      auto [a,b] = par[i];
      if (a > r) {
        if (hay) {
          ans.emplace_back(idx);
          r = par[idx].second;
          xd = r;
          hay = 0;
          if (r >= m) break;
        } else {
          can=0; break;
        }
      } 
      if (a > r) {can = 0; break;}
      else {
        if (b > xd) hay=1, idx = i, xd = b;
      }
    }
    if (hay) {
      ans.emplace_back(idx);
    }
    if (can and par[ans.back()].second < m) can = 0;
    if (can) {
      cout << sz(ans) << '\n';
      for(auto& i: ans) cout << par[i].first <<' ' <<par[i].second << '\n';
      cout << '\n';
    } else cout << "0\n\n";
  }
}


