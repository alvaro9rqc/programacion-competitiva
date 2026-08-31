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
  int blim=22;
  int lim = 1<<blim;
  vi dp(lim,-1);
  vi arr(n);
  for (auto i = 0; i < n; i++) {
    int x;cin>>x;
    dp[x]=i;
    arr[i]=x;
  }
  for (auto i = 0; i < blim; i++) {
    for (auto j = 0; j < lim; j++) 
      if(j&1<<i) dp[j]=max(dp[j], dp[j^1<<i]);
  }
  for(auto& i: arr) {
    int idx = dp[(lim-1)&~i];
    cout<<(idx==-1?-1:arr[idx])<<' ';
  }
  cout<<'\n';
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

