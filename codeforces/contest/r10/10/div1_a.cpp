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

string s;
int n; 
ll mod = 1e9+7;

ll inv(ll b) {
  ll e = mod-2;
  ll r = 1;
  while(e) {
    if(e&1) r*=b, r%=mod;
    b*=b; b%=mod;
    e>>=1;
  }
  return r;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt; cin >> tt;
  while(tt--){
    cin >>n;
    cin >> s;
    vector<vl>dp(2,vl(n));
    vector<vector<bool>> ismod(2, vector<bool>(n));
    ismod[0][0]=1;
    for (auto i = 1ll,sum=1ll; i < n; i++) {
      sum=(sum<<1)+(s[i]=='1');
      sum%=mod;
      if (sum==1) ismod[0][i]=1;
      if (sum+1==1) ismod[1][i]=1;
    }
    ll um = inv(2);
    dp[1][0]=1;
    for (auto i = 1; i < n; i++) {
      for (auto b = 0; b < 2; b++) {
        if(ismod[b][i]) dp[b][i]=0;
        else {
          int b1 = (s[i]=='1') +b;
          int b2 = b1/2;
          b1=b1/2+(b1&1);
          dp[b][i]= um*(1+dp[b1][i-1])%mod + um*(1+dp[b2][i-1])%mod;
          dp[b][i]%=mod;
        }
      }
      //raya;
    }
    cout << dp[0][n-1]<<'\n';
  }
}

