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
const ll INF = 1e18;
const int MOD = 1e9 + 7;

ll n, s;

ll is (ll dx, ll dy, ll x, ll y) {
  return 
  (dx==-1 and dy==-1 and (x == y)) or 
  (dx==-1 and dy==1 and (x == s-y)) or 
  (dx==1 and dy==-1 and (s-x == y)) or 
  (dx==1 and dy==1 and (s-x == s-y));

}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt; cin >> tt;
  while(tt--) {
    cin >> n>>s;
    vector<vl> a(n, vl(4));
    for(auto& e: a) cin >> e[0] >> e[1] >> e[2] >> e[3];
    ll ans = 0;
    for(auto& e: a) {
      if (is(e[0], e[1], e[2], e[3]))++ans;
    }
    cout << ans << '\n';
  }
}


