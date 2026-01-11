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
  int tt; cin >> tt;
  while(tt--) {
    int n; cin >> n;
    ll k; cin >> k;
    vl r(n), q(n);
    for(auto& i: q) cin>> i;
    for(auto& i: r) cin>> i;
    for(auto& i: q) {
      auto u = k - i + 1;
      auto d = 1 + i;
      i = u / d + (u%d?1:0);
    }
    sort(all(q));
    sort(all(r));
    int ans = 0;
    for (auto i = 0,j=0; i < n; i++) {
      if (q[i]>r[j]) ++ans, ++j;
    }
    cout << ans <<'\n';
  }
}


