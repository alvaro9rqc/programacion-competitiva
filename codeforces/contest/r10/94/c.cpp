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

void solve() {
  int n;cin>>n;
  vi arr(n); for(auto& i: arr) cin >> i;
  vi val=arr;
  sort(all(arr));
  int m = arr[n/2];
  vi dp(n+1);
  for (auto i = n-1; i >=0; i--) {
    //conca
    int hig=0,low=0,c=0;
    for (auto j = i; j < n; j++) {
      if(val[j]>m)hig++;
      else if(val[j]<m)low++;
      ++c;
      if(c%2==0)continue;
      if(hig<=c/2 and low<=c/2 and dp[j+1]) {
        dp[i]=max(dp[i],1+dp[j+1]);
      }
    }
    //all
    if(hig<=c/2 and low<=c/2 and c&1)
      dp[i]=max(dp[i],1);
  }
  cout<<dp[0]<<'\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt=1;
  cin>>tt;
  while(tt--) {
    solve();
  }
}

