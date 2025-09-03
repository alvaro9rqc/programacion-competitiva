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

struct Tree {
  typedef int T;
  static constexpr T unit = int(1e6);
  T f(T a, T b) { return min(a, b); } // (any associative fn )
  vector<T> s; int n;
  Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
  void update(int pos, T val) {
    for (s[pos += n] = val; pos /= 2;)
      s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
  }
  T query(int b, int e) { // query [ b , e)
    T ra = unit, rb = unit;
    for (b += n, e += n; b < e; b /= 2, e /= 2) {
      if (b % 2) ra = f(ra, s[b++]);
      if (e % 2) rb = f(s[--e], rb);
    }
    return f(ra, rb);
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n, m, q; cin >> n >> m >> q;
  vi per(n);
  for(auto& i: per) cin >> i, --i;
  vi idx(n);
  for (auto i = 0; i < n; i++) idx[per[i]] = i;
  vi mrr(m); 
  for(auto& i: mrr) cin >> i, --i;
  mrr.emplace_back(m);
  vi update(n, m);
  int lim = 18;
  vector<vi> jum(lim, vi(m+1));
  jum[0][m] = m;
  for (auto i = m-1; i >= 0; i--) {
    jum[0][i] = update[per[(idx[mrr[i]]+1)%n]];
    update[mrr[i]] = i;
  }
  for (auto i = 1; i < lim; i++) {
    for (auto j = 0; j < m+1; j++) jum[i][j] = jum[i-1][jum[i-1][j]];
  }
  int mask = n-1;
  for (auto i = 0; i < m; i++) {
    int v = i;
    for (auto j = 18; j >= 0; j--) 
      if (mask&1<<j) v = jum[j][v];
    mrr[i]=v;
  }
  Tree st(m);
  for (auto i = 0; i < m; i++) 
    st.update(i, mrr[i]);
  string ans;
  //for(auto& i: jum[1]) cout << i << ' ';
  //cout << '\n';
  //for(auto& i: mrr) cout << i << ' ';
  //cout << '\n';
  for (auto q_ = 0; q_ < q; q_++) {
    int l, r; cin >> l >> r;
    --l;
    int a = st.query(l, r);
    //dbg(a);
    ans.push_back(a < r? '1':'0');
  }
  cout << ans <<'\n';

}


