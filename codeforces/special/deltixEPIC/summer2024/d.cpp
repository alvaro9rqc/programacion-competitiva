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
    map<int,int> omp;
    for (auto i = 0; i < n; i++) {
      int x;cin>>x;
      ++omp[x];
    }
    vi arr;
    for(auto& [k,v]: omp) 
    arr.emplace_back(v);
    n = sz(arr);
    vector<vi> dp(n+5, vi(n+1));
    for (auto i = n-1; i >= 0; i--) {
      for (auto t = 0; t <= n; t++) {
        int ans = 1+dp[t+1][i+1];
        if (t>= arr[i]) ans=min(ans, dp[t-arr[i]][i+1]);
        dp[t][i]=ans;
      }
    }
    cout<<1+dp[1][1]<<'\n';
  }
}

