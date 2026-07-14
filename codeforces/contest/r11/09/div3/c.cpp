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
  int n,x,y;cin>>n>>x>>y;
  vi val(n);
  for(auto& i: val) cin >> i;
  vi ids(n+2);
  vi vis(n+2);
  int xd = 0;
  auto bfs=[&](int i) {
    queue<int> que;
    que.emplace(i);
    vis[i]=xd;
    while(sz(que)) {
      auto u = que.front(); que.pop();
      for(auto v : {u-x,u+x,u-y,u+y}) {
        if(v<0 or v>=n or vis[v]) continue;
        vis[v]=xd;
        que.emplace(v);
      }
    }
  };
  for (auto i = 0; i < n; i++) {
    if(!vis[i]) ++xd,bfs(i);
  }
  for (auto i = 0; i < n; i++) {
    ids[val[i]]=vis[i];
  }
  // for(auto& i: vis) cout<<i<<' ';
  // cout<<'\n';
  sort(all(val));
  bool can = 1;
  for (auto i = 0; i < n; i++) 
    if(vis[i]!=ids[val[i]])can=0;
  cout<<(can?"yes":"no")<<'\n';
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

