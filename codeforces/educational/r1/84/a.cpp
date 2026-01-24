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
    ll n, a; cin >> n >> a;
    ll r,l; r=l=0;
    vl arr(n);
    for(auto& i: arr) cin >> i;
    for(auto& i: arr) {
      if (i < a) ++l;
      else if (i > a) ++r;
    }
    ll ans = a-1;
    if (r > l) ans = a+1;
    cout << ans <<'\n';
  }
}

