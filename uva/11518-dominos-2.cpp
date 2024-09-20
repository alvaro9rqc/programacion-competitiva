#include <bits/stdc++.h> 
using namespace std;
int main () {
  ios_base::sync_with_stdio(false);
  int n, m, l, t; cin >> t;
  while (t--) {
    cin >> n; int x, y;
    vector<vector<int>> g(n, vector<int>());
    cin >> m>>l;
    //cout << n << " " << m <<" "<<l<<'\n';
    while (m--) {
      cin >> x >> y;
      g[--x].push_back(--y);
    }
    int c = 0;
    vector<bool> vis(n, false);
    while (l--) {
      int z; cin>>z;
      queue<int> q;
      q.push(--z);
      while (!q.empty()) {
        int v = q.front(); q.pop();
        if (! vis[v]) ++c;
        vis[v]=true; 
        for (int u : g[v]) {
          if (! vis[u]) q.push(u);
        }
      }
      //bfs
    }
    cout << c << '\n';
  }
  return 0;
}


