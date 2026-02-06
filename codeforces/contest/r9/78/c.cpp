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
  int tt; cin>>tt;
  while(tt--) {
    int n; cin >> n;
    vector<string> grid(2);
    cin>>grid[0]>>grid[1];
    auto win = [&](int i, int t) {
      if (t==0) 
        return ((grid[0][i]=='A')+(grid[1][i]=='A')+(grid[1][i+1]=='A'))>=2;
      else if (t==1)
        return ((grid[0][i]=='A')+(grid[1][i]=='A')+(grid[0][i+1]=='A'))>=2;
      else if (t==2)
        return ((grid[0][i]=='A')+(grid[0][i+1]=='A')+(grid[0][i+2]=='A'))>=2;
      else if (t==3)                                 
        return ((grid[1][i]=='A')+(grid[1][i+1]=='A')+(grid[1][i+2]=='A'))>=2;
      else if (t==4)                                 
        return ((grid[0][i]=='A')+(grid[1][i+1]=='A')+(grid[0][i+1]=='A'))>=2;
      else 
        return ((grid[0][i+1]=='A')+(grid[1][i]=='A')+(grid[1][i+1]=='A'))>=2;
    };
    int inf = 1e9;
    vector<vi> dp(3, vi(n+2,-inf));
    dp[1][n-2]=win(n-2,4);
    dp[0][n-2]=win(n-2,5);
    dp[2][n]=0;
    for (auto i = n-3; i >= 0; i--) {
      //2
      dp[2][i]= max({
          win(i,1)+dp[0][i+1],
          win(i,0)+dp[1][i+1],
          win(i,2)+win(i,3)+dp[2][i+3]
        
      });
      //1
      dp[1][i]=max(
        win(i,4)+dp[2][i+2],
        win(i,2)+win(i+1,3)+dp[1][i+3]
      );
      //0
      dp[0][i]=max(
        win(i,5)+dp[2][i+2],
        win(i+1,2)+win(i,3)+dp[0][i+3]
      );
    }
    cout<<dp[2][0]<<'\n';
  }
}

