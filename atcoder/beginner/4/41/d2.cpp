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
using vil = vector<pair<int,ll>>;
int n=int(1e5*2),l;
int ans = 0;
vector<bool>vis(n);
vector<vil>adj;

ll cost = 0, s, t;

void bt(int lev, int u) {
  if (lev == l) {
    if (!vis[u] and s <= cost and cost <= t)
      ++ans, vis[u]=1;
    return;
  } 
  for(auto& [v,w]: adj[u]) {
    cost+=w;
    bt(lev+1, v);
    cost-=w;
  }
}


int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int m;
  cin >> n >> m >> l >> s >> t;
  adj.assign(n, vil());
  for (auto i = 0; i < m; i++) {
    int u, v; ll c;
    cin >> u >> v >> c;
    --u,--v;
    adj[u].emplace_back(v,c);
  }
  bt(0,0);
  //cout << ans <<'\n';
  for (auto i = 0; i < n; i++) 
    if(vis[i])cout << i+1<<' ';
  cout <<'\n';
}

