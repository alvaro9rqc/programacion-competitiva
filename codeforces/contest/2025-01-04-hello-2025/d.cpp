#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

template<class T>
struct SegmentTree {
  int n;
  vector<T> info;

  SegmentTree(): n(0) {}

  SegmentTree( int n_, T v_ = T() ) {
    init(n_,v_);
  }

  template<class U>
    SegmentTree(vector<U> init_) {
      init(init_);
    }

  void init(int n_, T v_ = T()) {
    init(vector<T>(n_,v_));
  }
  
  template<class U>
    void init(vector<U> init_) {
      n = init_.size();
      int sz = (1<< ( __lg(n-1) +1 ));
      info.assign( sz * 2, T() );
      function<void(int,int,int)> build = [&](int v, int l, int r) {
        if (l == r) {
          info[v] = init_[l];
          return;
        }
        int m = (l+r) / 2;
        build(v+v, l, m);
        build(v+v+1,m+1,r);
        info[v] = info[v+v] + info[v+v+1];
      };
      build(1,0,n-1);
    }

  T rangeQuery(int v, int l, int r, int tl, int tr) {
    if (r < tl || l > tr) {
      return T();
    }
    if (l >= tl && r <= tr) return info[v];
    int m = (l+r) / 2;
    return rangeQuery(v+v, l, m, tl, tr) + rangeQuery(v+v+1, m+1, r, tl, tr);
  }

  T rangeQuery(int l, int r) {
    return rangeQuery(1,0, n-1, l, r);
  }

  void modify(int v, int l, int r, int i, const T &x) {
    if ( l == r ) {
      info[v] = x;
      return;
    }
    int m = (l + r) / 2;
    if (i <= m) {
      modify(v+v, l, m, i, x);
    } else {
      modify(v+v+1, m+1,r,i,x);
    }
    info[v] = info[v+v] + info[v+v+1];
  }

  void modify(int i, const T& x) {
    modify(1,0,n-1,i,x);
  }

  T query(int v, int l, int r, int i) {
    if (l == r) {
      return info[v];
    }
    int m = (l+r)/2;
    if (i <= m) {
      return query(v+v,l,m,i);
    } else return query(v+v+1, m+1,r,i);
  }

  T query(int i) {
    return query(1,0,n-1,i);
  }
};

const int INF = 1E9;

struct T {
  int min1, min2, max1, max2, ans1, ans2;
  T(): min1(INF), min2(INF), max1(-INF), max2(-INF), ans1(0), ans2(0) {}

  T(pair<int,int> x): min1(x.first), min2(x.second), max1(x.first), max2(x.second),
  ans1(0), ans2(0) {}
};

T operator+(const T& a, const T& b) {
  T res;
  res.min1 = min(a.min1, b.min1);
  res.min2 = min(a.min2, b.min2);
  res.max1 = max(a.max1, b.max1);
  res.max2 = max(a.max2, b.max2);
  res.ans1 = max({a.ans1, b.ans1, b.max1 - a.min1});
  res.ans2 = max({a.ans2, b.ans2, a.max2 - b.min2});
  return res;
}

void solve () {
  int n, q;
  cin >> n >> q;
  vi a(n);
  vector<ii> t(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    t[i] = {a[i]-i, a[i]+i-n+1};
  }
  SegmentTree<T> st(t);
  auto query = [&]() {
    return max(st.info[1].ans1, st.info[1].ans2);
  };
  cout << query() << '\n';
  for (int i = 0; i < q; ++i) {
    int p, x;
    cin >> p >> x;
    p--;
    t[p] = { x-p, x+p-n+1 };
    st.modify(p,t[p]);
    cout << query() << '\n';
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}


