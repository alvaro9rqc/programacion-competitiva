#include <bits/stdc++.h> 
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main () {
  ios_base::sync_with_stdio(false);
  int n, e;
  while (cin >> n) {
    if (n == 0) break;
    cin >> e;
    vector<vi> g(n, vi());
    for (int i =0; i < e; ++i) {
      int u, v;
      cin >> v >> u;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    int s = 0;
    queue<int> q; q.push(s);
    vi color(n, 6);
    color[s] = 0;
    bool is = true;
    while (!q.empty() && is) {
      int o = q.front(); q.pop();
      for (int& v : g[o]) {
        if (color[v] == 6) {
          color[v] = 1 - color[o];
          q.push(v);
        } else if (color[v] == color[o]){
          is = false;
          break;
        }
      }
    }
    if (is) cout << "BICOLORABLE.\n";
    else cout <<"NOT BICOLORABLE.\n";
  }
  return 0;
}


