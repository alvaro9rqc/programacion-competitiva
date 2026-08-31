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

ll fe(ll b, ll e) {
  ll r = 1;
  while(e) {
    if(e&1) r=(r*b)%mod;
    e>>=1;
    b=(b*b)%mod;
  }
  return r;
}

void solve() {
  int n;cin>>n;
  ll blim = 20;
  ll lim = 1<<blim;
  vl dp(lim);
  for (auto i = 0; i < n; i++) {
    ll x;cin>> x;
    ++dp[x];
  }
  // for (auto i = 0; i < lim; i++) dp[i]=( fe(2, i)-1+mod )%mod;
  for (auto i = 0; i < blim; i++) 
    for (auto j = lim-1; j >= 0; j--) 
      if(~j&1<<i) dp[j]=(dp[j]+dp[j^1<<i])%mod;
  ll ans = 0;
  for (auto i = 0; i < lim; i++) 
    if(__builtin_popcountll(i)&1) ans=(ans-fe(2,dp[i])+1+mod)%mod;
    else ans=(ans+fe(2,dp[i])-1)%mod;
  cout<<ans<<'\n';
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

