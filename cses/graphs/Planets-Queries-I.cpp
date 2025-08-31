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
  int lim = 31;
  int n; cin >> n;
  int qq; cin >> qq;
  vector<vi> mtx(lim, vi(n));
  for(auto& i: mtx[0]) cin >> i, --i;
  for (auto lev = 1; lev < lim; lev++) {
    for (auto i = 0; i < n; i++) {
      mtx[lev][i] = mtx[lev-1][mtx[lev-1][i]];
    }
  }
  for (auto q_ = 0; q_ < qq; q_++) {
    int x, k; cin >> x >> k;
    --x;
    for (auto i = lim-1; i >= 0; i--) 
      if ((1<<i)&k) x = mtx[i][x];
    cout << x+1 <<'\n';
  }
}


