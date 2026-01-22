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

int nro;
int n;
using vvi = vector<vi>;
vector<vvi> memo;

int dp(bool b, int k, int i) {
  if(i >= nro) return 0;
  if (memo[b][k][i]!=-1) return memo[b][k][i];
  int ans = 0;
  if (b) {
    if(n&1<<i) ans = 1+dp(1,k,i+1);
    else {
      //prenderlo
      if (k) ans = 1+dp(1,k-1,i+1);
      ans=max(ans,dp(0,k,i+1));
    }
  } else {
    ans=dp(0,k,i+1);
    if (n&1<<i and k) ans=max(ans,1+dp(1,k-1,i+1));
  }
  return memo[b][k][i]=ans;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt; cin >> tt;
  while(tt--){
    int k; 
    cin >> n>>k;
    nro = 31;
    for(;nro>=0 and not(n&1<<nro);--nro);
    nro++;
    int lso = 0;
    for(;lso<nro and not(n&1<<lso);++lso);
    int z = 0;
    for (auto i = lso; i < nro; i++) 
      if(not(n&1<<i))++z;
    if (k >= z+1) {
      k-=z+1;
      cout << (nro-lso+k)<<'\n';
    } else {
      memo.assign(2, vvi(k+1,vi(nro,-1)));
      cout << dp(0,k,0)<<'\n';
    }
  }
}

