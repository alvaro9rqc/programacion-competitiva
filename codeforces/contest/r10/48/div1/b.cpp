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
    for (; pos < sz(s); pos |= pos + 1) s[pos] = min(s[pos],dif);
  }
  ll query(int pos) { // sum of values in [0 , pos)
    ll res = inf;
    for (; pos > 0; pos &= pos - 1) res = min(res,s[pos-1]);
    return res;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt;cin>>tt;
  while(tt--) {
    int n,q;cin>>n>>q;
    vi val(n);
    for(auto& i: val) cin>>i;
    FT f1(n+1), f2(n+1), f3(n);
    for (auto i = n-1; i >= 0; i--) {
      f1.update(val[i],i);
      f2.update(val[i], f1.query(val[i]));
      f3.update(n-i-1 , f2.query(val[i]));
    }
    for (auto i = 0; i < q; i++) {
      int l,r;cin>>l>>r;
      --l,--r;
      cout<<(f3.query(n-l)>r?"yes":"no")<<'\n';
    }
  }
}

