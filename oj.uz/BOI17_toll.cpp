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
  int k, n, m, o;
  cin >> k >> n >> m >> o;
  int flen = (n-1) / k+1; 
  int lim = 16;
  const ll inf = ll(1e10);
  vector<vector<vl>> bj(lim, vector<vl>(n, vl(k,inf)));
  for (auto i = 0; i < m; i++) {
    int a, b; cin >> a>> b;
    ll x; cin >> x;
    bj[0][a][b%k] = x;
  }
  vi kpt(lim+1);
  for (auto i = 0; i < lim+1; i++) kpt[i] = k*(1<<i);
  for (auto lev = 1; lev < lim; lev++) {
    for (auto u = 0; u < n; u++) {
      int sts = kpt[lev-1];
      int lay = (u-u%k)+sts;
      if (u/k+(1<<lev) >= flen) break;
      for (auto v = 0; v < k; v++) {
        for (auto j = 0; j < k and lay+j<n; j++) {
          bj[lev][u][v] = min(
              bj[lev][u][v], bj[lev-1][u][j] + bj[lev-1][lay+j][v]
              );
        }
      }
    }
  }
  for (auto o_ = 0; o_ < o; o_++) {
    int a, b;
    cin >> a >> b;
    if ( a / k >= b / k ) {
      cout << -1 <<'\n';
    } else {
      int d = b/k - a/k;
      int lev = __builtin_ctz(d & -d);
      int base = a - a%k;
      vl pre(k, inf), now(k);
      for (auto i = 0; i < k; i++) {
        pre[i] = bj[lev][a][i];
      }
      //for(auto& i: bj[1][0]) {cout<<i<<':';}cout<<'\n';
      base+=kpt[lev++];
      for (; lev < lim; lev++) {
        if (d&1<<lev) {
          for (auto i = 0; i < k; i++) {//des
            ll xd = inf;
            for (auto j = 0; j < k; j++) {
              xd = min(xd, pre[j]+bj[lev][base+j][i]);
            }
            now[i]=xd;
          }
          base+=kpt[ lev ];
          swap(now, pre);
        }
      }
      cout << (pre[b%k]==inf?-1:pre[b%k])<<'\n';
    }
  }

}


