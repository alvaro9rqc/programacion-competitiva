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

vector<vi> adj;
vector<bool> vis;

void dfs(int u) {
  vis[u]= 1;
  for(auto& v: adj[u]) {
    if (not vis[v]) dfs(v);
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n, m;
  cin >> n >> m;
  adj.assign(n, vi());
  vis.assign(n, 0);
  for (auto i = 0; i < m; i++) {
    int x,y ; cin >> x >> y;
    --x,--y;
    adj[y].emplace_back(x);
  }
  int q; cin >> q;
  for (auto i = 0; i < q; i++) {
    int t, v; cin >> t >> v;
    --v;
    if (t == 1) {if(not vis[v])dfs(v);}
    else {
      cout << (vis[v]?"Yes":"No")<<'\n';
    }
  }
}

