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

struct FT {
  vector<ll> s;
  FT(int n) : s(n) {}
  void update(int pos, ll dif) { // a [pos] += dif
    for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
  }
  ll query(int pos) { // sum of values in [0 , pos)
    ll res = 0;
    for (; pos > 0; pos &= pos - 1) res += s[pos-1];
    return res;
  }
  int lower_bound(ll sum) {// min pos st sum of [0 , pos ] >= sum
    // Returns n if no sum is >= sum, or −1 if empty sum is
    if (sum <= 0) return -1;
    int pos = 0;
    for (int pw = 1 << 25; pw; pw >>= 1) {
      if (pos + pw <= sz(s) && s[pos + pw-1] < sum)
        pos += pw, sum -= s[pos-1];
    }
    return pos;
  }
  ll rs(int l, int r) {return query(r)-query(l);}
};


int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n,q; cin >> n >> q;
  FT ft(n);
  for (auto i = 0; i < n; i++) {
    int x; cin >> x;
    ft.update(i, x);
  }
  for (auto i = 0; i < q; i++) {
    int t; cin >> t;
    if (t == 1) {
      int x; cin >> x;
      --x;
      auto a = ft.rs(x,x+1);
      auto b = ft.rs(x+1,x+2);
      ft.update(x, -a+b);
      ft.update(x+1, a-b);
    } else {
      int l, r; cin>> l >> r;
      --l;
      cout << ft.rs(l, r)<<'\n';
    }
  }
}

