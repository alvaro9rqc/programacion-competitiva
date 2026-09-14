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
  int n,k;cin>>n>>k;
  vector<vi> ans(n,vi(n,-1));
  int x = 2*n-k;
  if(x<1 or x>n) {cout<<"-1\n";return;}
  int e = 1;
  for (auto i = 0; i < x; i++) ans[i][i]=e++;
  for (auto i = x; i < n; i++) {
    ans[i][x-1]=e++;
    ans[x-1][i]=e++;
  }
  for (auto i = 0; i < n; i++) {
    for (auto j = 0; j < n; j++) {
      if(ans[i][j]==-1)ans[i][j]=e++;
    }
  }
  for(auto& r: ans) {
    for(auto& c: r) {cout<<c<<' ';}
    cout<<'\n';
  }
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

