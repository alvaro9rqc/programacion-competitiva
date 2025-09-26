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

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt; cin >> tt;
  while(tt--) {
    ll n; cin >> n;
    set<ll> s;
    ll d = 10;
    for (auto i = 0; i < 18; ++i) {
      if (n % (d+1) == 0) s.insert(n / (d+1));
      d*=10;
    }
    if (not (sz(s))) {cout << 0 <<'\n'; continue;}
    cout << (sz(s)) <<'\n';
    for(auto& i: s) cout << i << ' ';
    cout << '\n';
  }
}


