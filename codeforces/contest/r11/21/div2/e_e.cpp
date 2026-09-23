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

ll mod = 998244353;
ll fe(ll b, ll e) {
  ll r = 1;
  while(e) {
    if(e&1) r=(r*b)%mod;
    b=(b*b)%mod;
    e>>=1;
  }
  return r;
}

void solve() {
  int n;cin>>n;
  vector<bool> isp(n+1,1);
  isp[0]=isp[1]=0;
  vl p(n+1,1);
  for (auto i = 2ll; i < n+1; i++) 
    if(isp[i]) {
      p[i]=i;
      for (auto j = i+i; j < n+1; j+=i) 
        p[j]*=i, isp[j]=0;
    }
  vector<vl> dp(n+1, vl(n+1,1));
  for (auto i = 2; i < n+1; i++) {
    dp[i][i]=i;
    for (auto j = i+1; j < n+1; j++) 
      if(p[i]%p[j]==0) dp[i][j]=dp[i-1][j-1];
      else dp[i][j]=dp[i][j-1];
  }
  vl arr(n);
  for(auto& i: arr) cin >> i;
  sort(all(arr));
  ll ans = 0;
  for (auto i = 0; i < n; i++) {
    ll mi = arr[i];
    ll ma = arr[i];
    ans=(ans+arr[i])%mod;
    for (auto j = i+1; j < n; j++) {
      mi=min(mi,arr[j]);
      ma=max(ma,arr[j]);
      ans=(ans+ dp[mi][ma]*fe(2,j-i-1)%mod)%mod;
    }
  }
  cout<<ans<<'\n';
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

