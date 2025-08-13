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
    map<int, int> m;
    int n; cin >> n;
    for (auto i = 0; i < n; ++i) {
      int x; cin >> x;
      ++m[x];
    }
    //for(auto& [k,v]: m) cout << k <<' '<<v<<'\n';
    
    int xd = min(m[0], m[1]);
    m[0]-=xd;
    m[1]-=xd;
    int ans = 2*xd;
    ans+=m[0];
    m[0]=0;
    //for(auto& [k,v]: m) cout << k <<' '<<v<<'\n';
    for(auto& [k,v]: m) ans+=v*k;
    cout << ans << '\n';
    
  }
}


