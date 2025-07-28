#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
#define endl '\n'
#define dbg(x) cerr << #x << " = " << (x) << endl;
#define raya cerr << " ==================== " << endl;
#define FOR(i, a, b) for (auto i = a; i < (b); ++i)
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt; cin >> tt;
  while(tt--) {
    int n; cin>> n;
    vl a(n);
    for(auto& e: a) cin >> e;
    ll ans = 0;
    for (ll i = 1; i <= n; ++i) {
      ans += (n-i+1) * i;
    }
    for (ll r = 1; r < n; ++r) {
      if (a[r-1] < a[r]) {
        ans-= r*(n-r);
      }
    }
    cout << ans << '\n';
  }
}


