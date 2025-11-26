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
  using iii = tuple<int,int,int>;
  while(tt--) {
    int n, k, t; cin >> n >> k >> t;
    vector<iii> dat(n);
    for(auto& i: dat) cin >> get<0>(i);
    for(auto& i: dat) cin >> get<2>(i);
    for(auto& i: dat) cin >> get<1>(i);
    sort(all(dat));
    vi dp(n);
    auto can = [&dat](int i, int j) {
      return abs(get<0>(dat[i]) - get<0>(dat[j])) >=
        abs(get<1>(dat[i]) - get<1>(dat[j]));
    };
    for (auto i = n-1; i >= 0; i--) {
      int p = get<2>(dat[i]);
      dp[i] = p;
      for (auto j = i+1; j < n; j++) {
        if (can(i,j))
          dp[i] = max(dp[i], p+dp[j]);
      }
    }
    int ans = 0;
    for (auto i = 0; i < n; i++) {
      if (get<0>(dat[i]) >= get<1>(dat[i]))
        ans = max(ans, dp[i]);
    }
    cout << ans <<'\n';
    if (tt) cout <<'\n';
  }
}

