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

char op='(',cl= ')';
ll mod =  998244353;

void solve() {
  vl dp[6];
  int n;cin>>n;
  for(auto& v: dp) v.assign(n+1,0);
  string s;cin>>s;
  vl bal(n);
  bal[0]=1;
  for (auto i = 1; i < n; i++) bal[i]+=bal[i-1]+(s[i]==op)-(s[i]==cl);
  for(auto& c: s) if(c==op)c=1;else c=-1;
  int tv[] = {-1,1},bv[]={-1,0,1};
  for (auto i = n-1; i >= 0; i--) {
    for(auto& ti: {0,1}) for(auto& bi: {0,1,2}) {
      auto t = tv[ti];
      auto b = bv[bi];
      ll ans = 0;
      //take
      if(t==s[i]) {
        ans+=(b==0);
        ans+=dp[3*ti+bi][i+1];
      } else { //diff
        // b+=t;
        if(bal[i]+2*(b+t)<0) {ans=0;}
        else {
          if(b+t==0)++ans;
          ans+=dp[3*(s[i]==1)+(b+t)+1][i+1];
        }
      }
      //no take
      if(bal[i]+2*b>=0) ans+=dp[3*ti+bi][i+1];
      dp[3*ti+bi][i]=ans;
    }
  }
  ll ans=0;
  for (auto i = 0; i < n; i++) 
    ans+=dp[0][i]+dp[3][i];
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

