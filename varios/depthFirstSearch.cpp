#include <iostream>
#include <vector>

vector<vector<int>> adj
vector<bool> visited
using namespace std;
void dfs(int u) {
  visited[u] = true;
  for (int v : adj[u]) {
    if (!visited[v]) 
      dfs(v);
  }
  
}

int main (int, char**) {
  int n = 5;
  adj.assing(n, vector<int>());
  // 0-1
  adj[0].push_back(1);
  adj[0].push_back(0);

  // 0-2
  adj[0].push_back(2);
  adj[0].push_back(0);

  // 2-1
  adj[0].push_back(2);
  adj[0].push_back(1);

  //marcar como visitados
  visited(n, false);
  for (int u = 0; u< n; u++) {
    if (!visited[u]) {
      //componente que inicia en u
      dfs(u);
    }
  }
}
