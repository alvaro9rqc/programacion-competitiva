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

void push(array<int,2>& p1, array<int,2>& p2) {
  int x[] ={p1[0],p1[1],p2[0],p2[1]};
  sort(all(x));
  p1[0]=x[3];
  p1[1]=x[2];
}

const int blim = 21;
const int lim = 1<<blim;
array<array<int,2>,lim> dp;

void solve() {
  int n;cin>>n;
  dp.fill({-1,-1});
  vi arr(n);
  for (auto i = 0; i < n; i++) {
    int x;cin>>x;
    arr[i]=x;
    swap(dp[x][0],dp[x][1]);
    dp[x][0]=i;
  }
  for (auto i = 0; i < blim; i++) 
    for (auto j = lim-1; j >= 0; j--) 
      if(~j&1<<i) push(dp[j], dp[j^1<<i]);
  int ans = 0;
  for (auto z = 0; z < n; z++) {
    int m = 0;
    int xd = -1;
    int x = arr[z];
    for (auto i = blim-1; i >= 0; i--) {
      if(~x&1<<i) {
        int m1 = m|1<<i;
        auto [k,j]=dp[m1];
        if(j>z) m = m1, xd=j;
      }
    }
    if(xd!=-1)
      ans=max(arr[xd]|x, ans);
  }
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

