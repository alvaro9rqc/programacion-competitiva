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
    ll n; cin >> n;
    vl a(n);
    for(auto& e: a) cin >> e;
    vl su(n);
    for (auto i = 0; i < n; ++i) {
      su[i] = (a[i]>>1) + 1;
    }
    ll m = 1e11;
    bool can = true;
    for (auto i = 0; i < n; ++i) {
      if (su[i] > m) {
        can = 0; break;
      } else {
        m = min ( m, a[i] );
      }
    }
    cout << (can ? "Yes":"No") <<  '\n';
  }
}


