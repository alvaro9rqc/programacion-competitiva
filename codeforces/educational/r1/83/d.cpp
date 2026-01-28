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
  const int lim = 31;
  const int limk = 31*31;
  vector<vector<bool>> dp(lim, vector<bool>(limk, 0));
  dp[1][0]=1;
  //i, k
  //for (auto k = 0; k < limk; k++) dp[1][k]=0;
  for (auto i = 2; i < lim; i++) {
    dp[i][0]=1;
    for (auto k = 1; k < limk; k++) {
      for (auto j = i; j > 1; j--) {
        int ap = (j-1)*(i-j+1);
        if (k - ap >= 0){
          if (dp[j-1][k-ap]) {
            dp[i][k]=1;
            break;
          }
        }
      }
      //dbg(dp[i][k]);
      //raya;
    }
  }
  int tt; cin >> tt;
  while(tt--) {
    int n,k ;cin >> n >> k;
    if (not dp[n][k]) {cout << "0\n";continue;}
    int ma,mi;
    ma=0;
    mi = 1;
    vi v;
    bool can = 1;
    for (auto i = n; i > 0; i--) {
      if (can)v.emplace_back(--mi);
      else v.emplace_back(++ma);
      //dbg(can);
      //dbg(i);
      if (!k) {can=0; continue;}
      for (auto j = i; j > 1; j--) {
        int ap = (j-1)*(i-j+1);
        if (k-ap>=0){
          if (dp[j-1][k-ap]) {
            //dbg(i);
            //dbg(k);
            //dbg(j);
            for (auto z = j; z < i; z++) 
              v.emplace_back(++ma);
            i=j;
            k-=ap;
            //dbg(k);
            //raya;
            break;
          }
        }
      }
    }
    for(auto& i: v) cout << i-mi+1<<' ';
    cout << '\n';
  }
}

