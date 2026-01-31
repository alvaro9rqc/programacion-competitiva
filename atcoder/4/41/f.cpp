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
  int n, m; cin>>n>>m;
  vi prr(n), vrr(n);
  for (auto i = 0; i < n; i++) {
    cin>>prr[i]>>vrr[i];
  }
  vector<vl> dp(m+1, vl(n));
  vector<vector<bool>> vis(m+1, vector<bool>(n));
  for (auto i = 0; i < m+1; i++) {
    dp[i][n-1]=i<prr[n-1]?0:vrr[n-1];
  }
  for (auto i = n-2; i >= 0; i--) {
    for (auto p = 0; p < m+1; p++) {
      if (p<prr[i]) dp[p][i]=dp[p][i+1];
      else 
        dp[p][i]=max(dp[p-prr[i]][i+1]+vrr[i], dp[p][i+1]);
    }
  }
  vi ans(n);
  queue<ii> que;
  que.emplace(m,0);
  vis[m][0]=1;
  while(sz(que)) {
    int l = sz(que);
    bool parte = 0;
    bool salta = 0;
    bool solo = 0;
    for (auto _ = 0; _ < l; _++) 
    {
      auto [p,i]=que.front(); que.pop();
      dbg(p);
      dbg(i);
      raya;
      if(i==n-1) {
        ans[i]=max(ans[i], (p<prr[i])?0:1);
        if (l>1) ans[i]=2;
        continue;
      }
      ll a = dp[p][i+1];
      ll b = 0;
      if (p>= prr[i])
        b = dp[p-prr[i]][i+1]+vrr[i];
      dbg(a);
      dbg(b);
      dbg(i);
      raya;
      if (b>a) {
        ans[i]=max(1,ans[i]);
        if (not vis[p-prr[i]][i+1])
          que.emplace(p-prr[i],i+1),vis[p-prr[i]][i+1]=1;
        if (l>1)ans[i]=2;
      } else if (b==a and dp[p][i]!=0) {
        ans[i]=2;
        if (not vis[p-prr[i]][i+1])
          que.emplace(p-prr[i],i+1), vis[p-prr[i]][i+1]=1;
        if (not vis[p][i+1])
          que.emplace(p,i+1), vis[p][i+1]=1;

      } else {
        if (not vis[p][i+1])
          que.emplace(p,i+1), vis[p][i+1]=1;
      }
    }
  }
  char xd[]= {'C','A','B'};
  dbg(dp[3][4]);
  for(auto& i: ans) cout << xd[i];
  cout<<'\n';
}

