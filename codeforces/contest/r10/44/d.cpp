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
    int n; cin >> n;
    vl hea(n);
    for(auto& ei: hea) cin>>ei;
    vl dp(n);
    dp[0] = hea[0];
    for (auto i = 1; i < n; i++) {
      //c
      ll ans = hea[i-1];
      if (hea[i]-i>0) ans+=hea[i]-i;
      ans+=(i-2>=0?dp[i-2]:0);
      //h
      ll ans2 = dp[i-1];
      if(hea[i]-1>0) ans2+=hea[i]-1;
      dp[i]=min(ans,ans2);
    }
    cout << dp.back() <<'\n';
  }
}


