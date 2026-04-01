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

vector<vl> memo;
vl val;
int n;
ll mod = 998244353;


ll dp(bool c, int i) {
  if(memo[c][i]!=-1) return memo[c][i];
  auto& ans=memo[c][i];
  if(val[i]<0) {
    if(c) ans = (n-1)*dp(0,i+1)+dp(1,i+1);
    else ans= dp(0,i+1);
  } else {
    if(c) ans = dp(val[i]==i+1, i+1);
    else ans = (val[i]==i-1)*dp(0,i+1);
  }
  return ans%=mod;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  cin>>n;
  val.resize(n);
  for(auto& i: val) cin >> i,--i;
  memo.assign( 2,
    vl(n+1, -1)
  );
  memo[0][n]=1;
  memo[1][n]=1;
  cout<<dp(1,0)<<'\n';
}

