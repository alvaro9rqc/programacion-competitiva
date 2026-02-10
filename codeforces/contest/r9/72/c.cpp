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

char ele[] = "narek";

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt;cin>>tt;
  while(tt--) {
    int n,ss;cin>>n>>ss;
    vector<vi> pts(5), fin(5);
    for (auto _ = 0; _ < n; _++) {
      string s;cin>>s;
      for (auto i = 0; i < 5; i++) {
        int j = i;
        int to=0, se=0;
        for(auto& c: s) {
          if(c==ele[j])++se,j=(j+1)%5;
          if(strchr(ele,c)!=nullptr)++to;
        }
        pts[i].emplace_back(2*se-to);
        fin[i].emplace_back(j);
      }
    }
    // for (auto j = 0; j < n; j++) {
    //   for (auto i = 0; i < 5; i++) {
    //   dbg(pts[i][j]);
    //   dbg(fin[i][j]);
    //   }
    // raya;
    // }
    vector<vi>dp(5, vi(n));
    for (auto i = 0; i < 5; i++) {
      dp[i].back()=max(pts[i].back()-2*fin[i].back(), -2*i);
    }
    for (auto i = n-2; i >= 0; i--) {
      for (auto t = 0; t < 5; t++) {
        dp[t][i]=max(
          pts[t][i]+dp[fin[t][i]][i+1],
          dp[t][i+1]
        );
      }
    }
    cout<<dp[0][0]<<'\n';
  }
}

