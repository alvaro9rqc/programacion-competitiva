#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int nav=0;
vector<vi> g;

vi visited;

int dfs(int v) {
  int n = 1;
  visited[v]=1;
  for(auto& u: g[v]) {
    if (visited[u]) continue;
    n += dfs(u);
  }
  return n;
}


int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  g.assign(n, vi());
  visited.assign(n, 0);
  while (m--) {
    int x, y; cin >> x >> y;
    x--;y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for (auto i = 0; i < n; ++i) {
    if (not visited[i]) {
      int f = dfs(i);
      if (f > nav) nav = f;
    }
  }
  cout <<nav <<'\n';
  return 0;
}


