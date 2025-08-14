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
    int n; cin >> n;
    vl mon(n); 
    for(auto& e: mon) cin >> e;    
    vector<pair<ll,ll>> dp(n);
    dp[0] = {1,1};
    for (auto i = 1; i < n; ++i) {
      ll v=0, c=0;
      for (auto j = 0; j < i; ++j) {
        auto [a,b] = dp[j];
        if (b >= c ) {
          if (b == c and a > v) continue;
          auto it = upper_bound(mon.begin()+j+1, mon.begin()+i+1, a);
          int d = int(it-mon.begin());
          if (d -1 == j) v=a,c=b;
        }
      }
      dp[i] = {v+mon[i], ++c};
    }
    cout << dp.back().second << '\n';
  }
}


