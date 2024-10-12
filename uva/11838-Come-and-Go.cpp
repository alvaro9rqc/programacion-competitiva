#include <bits/stdc++.h> 
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
enum{ UNV = -1 };

int dfsNumberCounter, numSCC;
vi dfs_num, dfs_low, visited;
stack<int> st;
vector<vi> graph;

void tarjanSCC(int u) {
  dfs_low[u] = dfs_num[u] = dfsNumberCounter;
  dfsNumberCounter++;
  st.push(u);
  visited[u] = 1;
  for(auto& v : graph[u]) {
    if (dfs_num[v] == UNV)
      tarjanSCC(v);
    if (visited[v])
      dfs_low[u] = min(dfs_low[u], dfs_low[v]);
  }
  if (dfs_low[u] == dfs_num[u]) {
    ++numSCC;
    while(1) {
      int v =st.top(); st.pop();
      visited[v] = 0;
      if ( u == v ) break;
    }
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  int n, m, v,w,p;
  while (cin >> n >> m) {
    if (n == 0 && m == 0) break;
    graph.assign(n, vi());
    for (auto i = 0; i < m; ++i) {
      cin >> v >> w>> p;
      --v; --w;
      if (p == 1) {
        graph[v].push_back(w);
      } else {
        graph[v].push_back(w);
        graph[w].push_back(v);
      }
    }
    dfsNumberCounter = numSCC =0;
    dfs_num.assign(n, UNV); dfs_low.assign(n, 0); visited.assign(n,0);
    for (auto i = 0; i < n; ++i) {
      if (dfs_num[i] == UNV)
        tarjanSCC(i);
    }
    //cout << "->"<< numSCC<<'\n';
    if (numSCC == 1) cout << "1\n";
    else cout << "0\n";
  }
  return 0;
}


