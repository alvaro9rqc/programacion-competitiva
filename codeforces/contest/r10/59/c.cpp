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
    ll a, b; cin >> a >> b;
    int idx = 32;
    for (; idx >=0; idx--) {
      if ((1<<idx&a) or(1<<idx&b)) break;
    }
    if ( (1<<idx&b) and not(1<<idx&a) ) {
      cout << "-1\n"; continue;
    }
    int k  = 0;
    vl ans;
    for (ll i = 0;i<=idx;++i) {
      if (( 1ll<<i&a ) != (1ll<<i&b)) {
        ++k;
        ans.emplace_back(1ll<<i);
      }
    }
    cout <<k<<'\n';
    if(not k) continue;
    for(auto& i: ans) cout << i <<' ';
    cout <<'\n';
  }
}

