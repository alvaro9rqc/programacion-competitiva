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
vl fac;

ll fe(ll b, ll e) {
  ll r = 1;
  while(e) {
    if(e&1) r=r*b%mod;
    e>>=1;
    b=b*b%mod;
  }
  return r;
}

ll com(ll n, ll r) {
  return fac[n]*fe(fac[r]*fac[n-r]%mod,
                   mod-2
                   )%mod;
}

ll way(ll r) {
  ll ans = 0;
  for (auto i = 0ll; i < r+1; i++) {
    // dbg(fac[i]*com(r,i));
    ans+=fac[i]*com(r,i);
    ans%=mod;
  }
  return ans;
}

void solve() {
  ll n,m;cin>>n>>m;
  ll lim = 1<<m;
  fac.assign(n+1,0);
  for (auto i = 0; i < m; i++) {
    string s;cin>>s;
    for (auto j = 0; j < n; j++) 
      if(s[j]=='H') fac[j]|=1<<i;
  }
  map<ll,int> omp;
  vl dp(lim,1);
  for (auto i = 0; i < n; i++) ++omp[fac[i]];
  fac[0]=fac[1]=1;
  for (auto i = 2; i < n+1; i++) 
    fac[i]=i*fac[i-1]%mod;
  for(auto& [k,v]: omp) dp[k]=way(v);
  for (auto i = 0; i < m; i++) 
    for (auto j = 0; j < lim; j++) 
      if(j&(1<<i)) dp[j]=dp[j]*dp[j^(1<<i)]%mod;
  cout<<( dp[lim-1]-1+mod ) % mod<<'\n';
  dbg(way(3));
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt=1;
  // cin>>tt;
  while(tt--) {
    solve();
  }
}

