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
  int tt;cin>>tt;
  while(tt--){
    int n;cin>>n;
    vi arr(n); for(auto& i: arr) cin>>i;
    vector<vi>dp(3,vi(n));
    dp[0][0]=arr[0]>0;
    dp[1][0]=arr[0]>2;
    dp[2][0]=arr[0]>0;
    for (auto i = 1; i < n; i++) {
      if (not arr[i]) {
        dp[0][i]=dp[0][i-1];
        dp[1][i]=dp[0][i-1];
        dp[2][i]=dp[0][i-1];
        continue;
      }
      //0
      dp[0][i]=1+dp[0][i-1];
      if (arr[i]<=2) 
        dp[0][i]=min(dp[0][i], dp[1][i-1]+1);
      //1
      if(arr[i]<=2) 
        dp[1][i]=dp[0][i-1];
      else {
        dp[1][i]=1+dp[0][i-1];
        if (arr[i]<=4)
          dp[1][i]=min(dp[1][i],1+dp[2][i-1]);
      }
      //2
      if (arr[i]<=4)
        dp[2][i]=1+dp[1][i-1];
      else 
        dp[2][i]=dp[0][i-1]+1;
    }
    cout<<dp[0][n-1]<<'\n';
  }
}

