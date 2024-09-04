#include <bits/stdc++.h> 
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
int dfs(vector<vi>& g, vector<bool>& vis, int u) {
  int c = 1;
  vis[u] = true;
  for (auto & v : g[u]){
    if (! vis[v])
      c+=dfs(g, vis, v);
  }
  return c;
}
int main () {
  while (1){
    int n, m; cin >> n >> m;
    if (n==0&&m==0) break;
    map<int, vii> EL;
    //vector<vii> EL(m, vii());
    int max = INT_MIN;
    while (m--) {
      int v, u, w; cin >> v >> u>>w;
      --u;--v;
      if (w > max) max = w;
      EL[w];
      EL[w].emplace_back(v, u);
      EL[w].emplace_back(u, v);
    }
    vector<vi> g(n, vi());
    for (auto &[u, v]:EL[max]) 
    {
      g[u].push_back(v);
      g[v].push_back(u);
    }
    vector<bool> vis(g.size(), false);
    int numCC =0;
    for (int u=0; u < g.size(); ++u) 
      if (!vis[u]) {
        int temp = dfs(g, vis, u);
        if (temp > numCC) numCC = temp;
      }
    cout << numCC << '\n';
    //cout << n << ' '<< max<< '\n';
  }
}

