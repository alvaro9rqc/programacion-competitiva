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
  vl val(n);
  for(auto& i: val) cin >> i; 
  vector<vl> dp(2, vl(n));
  const bool ma=1,mi=0;
  dp[ma][0]=max(val[0],-val[0]);
  dp[mi][0]=min(val[0],-val[0]);
  for (auto i = 1; i < n; i++) {
    ll ori,def;
    // min
    ori=val[i]+dp[mi][i-1];
    def=-val[i]-dp[ma][i-1];
    dp[mi][i]=min(ori,def);
    // max
    ori=val[i]+dp[ma][i-1];
    def=-val[i]-dp[mi][i-1];
    dp[ma][i]=max(ori,def);
  }
  auto s = dp[mi].back();
  bool f = mi;
  vector<bool> res(n);
  ll k =0;
  for (auto i = n-1; i >= 1; i--) {
    ll ori;
    if(f==mi) {
      ori=val[i]+dp[mi][i-1];
      // def=-val[i]-dp[ma][i-1];
      if(s==ori)
        s=dp[mi][i-1];
      else 
        s=dp[ma][i-1],f=ma,res[i]=1,++k;
    } else {
      ori=val[i]+dp[ma][i-1];
      // def=-val[i]-dp[mi][i-1];
      if(s==ori) 
        s=dp[ma][i-1];
      else 
        s=dp[mi][i-1],f=mi,res[i]=1,++k;
    }
  }
  // base
  if(s!=val[0])res[0]=1,++k;
  cout<<k<<'\n';
  for (auto i = n-1; i >= 0; i--) {
    if(res[i])cout<<i+1<<' ';
  }
  cout<<'\n';
  // cout<<dp[mi].back()<<'\n';
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

