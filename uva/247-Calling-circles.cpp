#include <bits/stdc++.h> 
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
enum { UNVISITED = -1 };

unordered_map<string, unordered_set<string>> graph;
unordered_map<string, int> dfs_num, dfs_low, visited;
stack<string> st;
unordered_set<string> names;
int dfsNumberCounter;

void tarjanSCC(string u) {
  dfs_low[u] = dfs_num[u] =  dfsNumberCounter;
  ++dfsNumberCounter;
  st.push(u);
  visited[u] = 1;
  for (auto& v : graph[u]) {
    if (dfs_num[v] == UNVISITED)
      tarjanSCC(v);
    if (visited[v])
      dfs_low[u] = min(dfs_low[u], dfs_low[v]);
  }
  if (dfs_low[u] == dfs_num[u]) {
    while(1) {
      string v = st.top(); st.pop();
      //cout << "--- " << v <<"-"<<u<<'\n';
      visited[v] = 0;
      if (u == v) {
        cout << v << '\n';
        break;
      } else cout << v << ", "; 
    }
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  int n, m, counter=0;
  cin >> n>> m;
  while (1) {
    graph.clear();
    dfs_num.clear();
    dfs_low.clear();
    visited.clear();
    names.clear();
    for (int i = 0; i < m; ++i) {
      string u, v;
      cin >> u >> v;
      graph[u].insert(v);
      names.insert(u);
      names.insert(v);
    }
    for(auto& s:names){
      dfs_num[s] = UNVISITED;
      dfs_low[s] = 0;
      visited[s] = 0;
    }
    dfsNumberCounter=0;
    while(!st.empty()) st.pop();
    cout << "Calling circles for data set "<<++counter<<":\n";
    for (auto s : names) {
      //cout << "check " << s << '\n';
      if (dfs_num[s] == UNVISITED) tarjanSCC(s);
    }
    
    cin >> n>> m;
    if (n == 0 && m == 0) break;
    else cout << '\n';
  } 
  return 0;
}


