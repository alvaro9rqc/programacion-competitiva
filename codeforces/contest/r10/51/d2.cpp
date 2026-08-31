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

ll mod = 1e9+7;
inline ll modsum(ll a, ll b) {
  return (a+b)%mod;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt; cin >> tt;
  const int H = 2001;
  while(tt--) {
    int n; cin >> n;
    vl arr(n); for(auto& i: arr) cin>>i;
    vector<vector<vl>> dp(2, vector<vl>(H, vl(n+1)));
    for (auto i = 0; i < H; i++) 
      dp[0][i][n]=dp[1][i][n]=1;
    for (auto i = n-1; i >= 0; i--) {
      for (auto h = 0; h < H; h++) {
        //p
        ll ans = 0;
        if(arr[i]>=h) ans=modsum(ans,dp[1][h][i+1]);
        ans=modsum(ans,dp[1][h][i+1]);
        dp[1][h][i]=ans;
        // not p
        ans=0;
        ans=modsum(ans,dp[1][0][i+1]);
        ans=modsum(ans,dp[0][0][i+1]);
        dp[0][h][i]=ans;
      }
    }
    cout<<dp[0][0][0]<<'\n';
  }
}

