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

inline ll kmod(ll x, ll m) {
  return (x%m+m)%m;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int t, k;
  cin >> t >> k;
  int lim = ll(1e5+10);
  vl g(lim, 1);
  ll mod = ll(1e9+7);
  for (int i = k; i < lim; ++i) {
    g[i] = kmod(g[i-1] + g[i-k], mod);
  }
  for (auto i = 1; i < lim; ++i) {
    g[i] = kmod(g[i]+g[i-1], mod);
  }
  for (auto i = 0; i < t; ++i) {
    int a, b; cin >> a >> b;
    cout << kmod(g[b] - g[a-1], mod) << '\n';
  }
}


