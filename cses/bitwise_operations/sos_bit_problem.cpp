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
  int blim = 20;
  int lim = 1<<blim;
  vi dp(1<<blim);
  vi arr(n);
  map<int,int> omp;
  for(auto& i: arr) {
    cin>>i;
    ++omp[i];
    ++dp[i];
  }
  vi dp2 = dp;
  for (auto i = 0; i < blim; i++) 
    for (auto j = 0; j < (lim); j++) 
      if(j&(1<<i))dp[j]+=dp[j^(1<<i)];
  for (auto i = 0; i < blim; i++) 
    for (auto j = lim-1; j >= 0; j--) 
      if((~j)&(1<<i))dp2[j]+=dp2[j^(1<<i)];
  for(auto& i: arr) {
    printf("%d %d %d\n", dp[i], dp2[i], n-dp[(lim-1)^i]);
  }
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

