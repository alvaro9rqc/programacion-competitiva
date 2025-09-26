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
#define all(x) begin(x), end(x)

class SegmentTree {
  private: 
    int n;
    vi A, st, lazy;
    int l(int p) {return p<<1;}
    int r(int p) {return (p<<1)+1;}

    int conquer(int a, int b) {
      if (a == -1) return b;
      if (b == -1) return a;
      return a + b;
    }

    void build(int p, int L, int R) {
      if (L == R) st[p] = A[L];
      else {
        int m = (L+R)/2;
        build(l(p), L, m);
        build(r(p), m+1, R);
        st[p] = conquer(st[l(p)], st[r(p)]);
      }
    }

    void ref(int p, int L, int R, int v) {
      int d = R - L + 1;
      if (v == 2) st[p] = d - st[p];
      else st[p] = d*v;
      if (L == R) A[L] = st[p];
    }

    void propagate(int p, int L, int R) {
      if (lazy[p] == -1) return;
      int m = (L+R)/2;
      if (L == R) {
        lazy[p] = -1;
        return;
      }
      ref(l(p), L, m, lazy[p]);
      ref(r(p), m+1, R, lazy[p]);
      if (lazy[p] == 2) {
        if (lazy[l(p)] == 2) lazy[l(p)] =-1;
        else if(lazy[l(p)] == -1) lazy[l(p)] = 2;
        else lazy[l(p)] = 1 - lazy[l(p)];
        if (lazy[r(p)] == 2) lazy[r(p)] =-1;
        else if(lazy[r(p)] == -1) lazy[r(p)] = 2;
        else lazy[r(p)] = 1 - lazy[r(p)];
      } else {
        lazy[l(p)] = lazy[r(p)] = lazy[p];
      }
      lazy[p] = -1;
    }

    int RQ(int p, int L, int R, int i, int j) {
      if (i > j) return 0;
      if ((i <= L) and (R <= j)) {
        //cerr << p <<'.'<<L<<' '<<R<<' '<<i<<' '<<j<<' '<<st[p]<<'\n';
        return st[p];
      }
      propagate(p, L, R);
      int m = (L+R)/2;
        auto xd1 = RQ(l(p), L, m, i, min(m,j));
        auto xd2 = RQ(r(p), m+1, R, max(i,m+1), j);
        //cerr << p <<':'<<L<<' '<<R<<' '<<i<<' '<<j<<' '<<st[p]<<'\n';
        //cerr << p <<':'<<xd1 <<' '<< xd2<<'\n';
      return conquer(
          xd1,xd2
          );
    }

    void update(int p, int L, int R, int i, int j, int val) {
      if (i > j) return;
        propagate(p, L, R);
      if ((L >= i) and (R <= j)) {
        lazy[p] = val;
        ref(p, L, R, val);
        //cerr << p << ':' << L << ' ' << R <<' ' << i <<' '<<j<<' '<<val<<' '<<st[p]<<'\n';
      } else {
        int m = (L+R) / 2;
        update(l(p), L, m, i, min(m,j), val);
        update(r(p), m+1, R, max(i,m+1), j, val);
        //int lsubtree = (lazy[l(p)] != -1? lazy[l(p)]: st[l(p)]);
        //int rsubtree = (lazy[r(p)] != -1? lazy[r(p)]: st[r(p)]);
        //st[p] += rsubtree + lsubtree;
        //st[p] = conquer(
        //  RQ(l(p), L, m, L, m),
        //  RQ(r(p), m+1, R, m, R)
        //  );
        st[p] = st[l(p)] + st[r(p)];
        //st[p] = (lsubtree <= rsubtree) ? st[l(p)] : st[r(p)];
        //cerr << p << ':' << L << ' ' << R <<' ' << i <<' '<<j<<' '<<val<<' '<<st[p]<<'\n';
      }
    }
  public:
    SegmentTree(int sz) : n(sz), st(4*n), lazy(4*n,-1) {}

    SegmentTree(const vi &initialA): SegmentTree(int(initialA.size())) {
      A = initialA;
      build(1,0,n-1);
    }

    void update(int i, int j, int val) { update(1,0,n-1,i,j,val); }

    int RQ(int i, int j) { return RQ(1,0,n-1,i,j); }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt; cin >> tt;
  int casos = 0;
  while(casos++ < tt) {
    vi arr;
    int m; cin >> m;
    for (auto i = 0; i < m; ++i) {
      int r; cin >> r;
      string s; cin >> s;
      for (auto j = 0; j < r; ++j) 
        for(auto& e: s) arr.emplace_back(int(e-'0'));
    }
    SegmentTree st(arr);
    int q; cin >> q;
    cout << "Case " << casos <<":" << '\n';
    int gaaa = 1;
    //st.update(0, sz(arr)-1, 0);
    for (auto i = 1; i <= q; ++i) {
      char ty; cin >> ty;
      int a, b; cin >> a >> b;
      if (a > b) swap(a,b);
      if (ty == 'F') {
        st.update(a,b,1);
      } else if (ty == 'E') {
        st.update(a,b,0);
      } else if (ty == 'I') {
        st.update(a,b, 2);
      } else cout << "Q" << gaaa++ << ": " << st.RQ(a, b) <<'\n';
    }
  }
}


