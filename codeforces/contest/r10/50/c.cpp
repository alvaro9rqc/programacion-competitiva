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
    int n; ll m; cin >> n >> m;
    ll time = 0, side = 0;
    ll ans = 0;
    for (auto i = 0; i < n; i++) {
      ll a, b; cin >> a >> b;
      ll p = a -time;
      if (b==side) {
        ans+=(p%2==0?p:p-1);
      } else {
        ans+=(p&1?p:p-1);
      }
      time = a;
      side = b;
    }
    ans+= m - time;
    cout << ans <<'\n';
  }
}

