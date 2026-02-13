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

vector<vector<ii>> adj;
vector<bool> vis;

int dfs(int u, int m) {
  vis[u]=1;
  auto xd = m;
  for(auto& [v, c]: adj[u]) {
    if (not vis[v]) {
      m^=(dfs(v, xd^c));
    }
  } 
  return m;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt;cin>> tt;
  while(tt--) {
    int n, m;cin>>n>>m;
    vis.assign(n, 0);
    adj.assign(n, vector<ii>());
    for (auto i = 0; i < m; i++) {
      int a, b, c;cin>>a>>b>>c;
      --a,--b;
      adj[a].emplace_back(b, c);
      adj[b].emplace_back(a, c);
    }
    if ((n&1)) {
      cout<<"-1\n";
      continue;
    }
    int x = dfs(0,0);
    int y = 0;
    for (auto i = 0; i < n+1; i++) 
      y^=i;
    cout<<(y^x)<<'\n';
  }
}

