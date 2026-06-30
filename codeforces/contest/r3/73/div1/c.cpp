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

ll mod = 1e9+7;

template<class T, int N> struct Matrix {
  typedef Matrix M;
  array<array<T, N>, N> d{};
  M operator*(const M& m) const {
    M a;
    rep(i,0,N) rep(j,0,N)
    rep(k,0,N) a.d[i][j] += d[i][k]*m.d[k][j], a.d[i][j]%=mod;
    return a;
  }
  M operator+(const M& m) const {
    M a;
    rep(i,0,N) rep(j,0,N)
      a.d[i][j] += d[i][j]+m.d[i][j], a.d[i][j]%=mod;
    return a;
  }
  array<T, N> operator*(const array<T, N>& vec) const {
    array<T, N> ret{};
    rep(i,0,N) rep(j,0,N) ret[i] += d[i][j] * vec[j],ret[i]%=mod;
    return ret;
  }
  M operator^(ll p) const {
    assert(p >= 0);
    M a, b(*this);
    rep(i,0,N) a.d[i][i] = 1;
    while (p) {
      if (p&1) a = a*b;
      b = b*b;
      p >>= 1;
    }
    return a;
  }
};

using M = Matrix<ll,2>;
M base,zero,one,d2 ;

const int inf = 1e9;
struct Node {
  Node *l = 0, *r = 0;
  ll lo, hi=0;
  M madd = one;
  bool xd=0;
  M val = zero;
  Node(ll _lo, ll _hi) : lo(_lo), hi(_hi) {} // Large interval of −in f
  Node(vector<M>& v, ll _lo, ll _hi) : lo(_lo), hi(_hi) {
    if (lo + 1 < hi) {
      ll mid = lo + (hi - lo) / 2;
      l = new Node(v, lo, mid);
      r = new Node(v, mid, hi);
      val = (l->val+ r->val);
    } else {
      val = v[lo];
    }
  }
  M query(ll L, ll R) {
    if (R <= lo || hi <= L) return zero;
    if (L <= lo && hi <= R) return val;
    push();
    return(l->query(L, R)+ r->query(L, R));
  }
  void add(ll L, ll R, M x) {
    if (R <= lo || hi <= L) return;
    if (L <= lo && hi <= R) {
      xd=1;
      madd = madd*x;
      val =val* (x);
    } else {
      push();
      l->add(L, R, x);
      r->add(L, R, x);
      val = (l->val + r->val);
    }
  }
  void push() {
    if (!l) {
      ll mid = lo + (hi - lo) / 2;
      l = new Node(lo, mid);
      r = new Node(mid, hi);
    }
    if (xd) {
      l->add(lo, hi, madd);
      r->add(lo, hi, madd);
      madd = one;
      xd=0;
    }
  }
};


void solve() {
  int n,q;cin>>n>>q;
  vector<M> val(n,base);
  for (auto i = 0; i < n; i++) {
    ll x;cin>>x;
    val[i]=val[i]^(x);
  }
  // dbg(val[0].d[1][0]);
  // dbg(val[1].d[1][0]);
  // dbg(val[2].d[1][0]);
  // dbg(val[3].d[1][0]);
  // dbg(val[4].d[1][0]);
  Node lst(val,0,n);
  for (auto _ = 0; _ < q; _++) {
    int l,r;
    int tp;cin>>tp>>l>>r;
    if(tp==1) {
      ll x;cin>>x;
      lst.add(l-1,r,base^x);
    } else {
      auto m = lst.query(l-1,r);
      // cout<<(m.d[1][0]+m.d[1][1])<<'\n';
      cout<<(m.d[1][0])<<'\n';
    }
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  base.d={{
    {1, 1},
    {1, 0}
  }};
  zero.d={{
    {{0,0}},
    {{0,0}}
  }};
  one.d={{
    {{1,0}},
    {{0,1}},
  }};
  d2.d={{
    {{-2,0}},
    {{-1,0}},
  }};
  cin.exceptions(cin.failbit);
  int tt=1;
  // cin>>tt;
  while(tt--) {
    solve();
  }
}

