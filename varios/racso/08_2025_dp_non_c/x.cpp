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

ll mmm = ll(1e9 +7);
inline ll mod(ll b) {
  return (b%mmm+mmm)%mmm;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n; cin >> n;
  string s; cin >> s;
  vl next(n, 1), now(n);
  for (auto i = 1; i < n; ++i) {
    next[i] += next[i-1];
  }
  auto sum = [&next](int l, int r) {
    if (r < l) return 0ll;
    return mod(next[r] - (l?next[l-1]:0));
  };
  for (auto i = n-1; i > 0; --i) {
    int lim = n - i;
    if (s[i-1] == '<') {
      for (auto j = 0; j <= lim; ++j) {
        //dbg(j);
        //dbg(lim);
        //dbg(sum(j,lim-1));
        //raya;
        now[j] = sum(j, lim-1);
      }
    } else {
      for (auto j = 0; j <= lim; ++j) {
        now[j] = sum(0, j-1);
      }
    }
    for (auto i = 1; i <= lim; ++i) now[i]+=now[i-1], now[i]%=mmm;
    swap(now,next);
  }
  cout << next.back() <<'\n';
}


