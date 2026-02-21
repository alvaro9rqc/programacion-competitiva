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

const int inf=1e8;

struct FT {
  vector<ll> s;
  FT(int n) : s(n,inf) {}
  void update(int pos, ll dif) { // a [pos] += dif
    for (; pos < sz(s); pos |= pos + 1) s[pos]= min(s[pos],dif);
  }
  ll query(int pos) { // sum of values in [0 , pos)
    ll res = inf;
    for (; pos > 0; pos &= pos - 1)
      res=min(s[pos-1],res);
    return res;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt;cin>>tt;
  while(tt--) {
    int n, q;cin>>n>>q;
    vi arr(n); for(auto& i: arr) cin>>i,--i;
    FT f1(n),f2(n),f3(n);
    int m=n-1;
    for (auto i = n-1; i >= 0; i--) {
      f1.update(arr[i], i);
      if (i<=n-2) f2.update(arr[i], f1.query(arr[i]));
      if (i<=n-3) f3.update(m-i,f2.query(arr[i]));
    }
    for (auto _ = 0; _ < q; _++) {
      int l, r;cin>>l>>r;
      --l,--r;
      ll u = f3.query(m+1-l);
      cout<<(u<=r?"no":"yes")<<'\n';
    }
  }
}

