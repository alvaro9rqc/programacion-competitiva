#include <bits/stdc++.h> 
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
enum { UNVISITED =-1 };

unordered_map<string, unordered_set<string>> graph;
unordered_map<string, int> dfs_num, dfs_low, visited; 
stack<string> st;
int dfsNumberCounter, numSCC;

void tarjanSCC(const string& u) {
  dfs_num[u] = dfs_low[u] = dfsNumberCounter;
  ++dfsNumberCounter;
  st.push(u);
  visited[u] = 1;
  for (auto& v : graph[u]) {
    if (dfs_num[v] == UNVISITED)
      tarjanSCC(v);
    if (visited[v]) dfs_low[u] = min ( dfs_low[u], dfs_low[v] ) ;
  }
  if(dfs_low[u] == dfs_num[u]) {
    ++numSCC;
    while(1){
      string v = st.top(); st.pop();
      visited[v] = 0;
      if (v == u) break;
    }
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  int p, t;
  while (cin >> p >> t) {
    cin >> ws;
    if (p == 0 && t == 0) break;
    graph.clear();
    dfs_num.clear();
    dfs_low.clear();
    visited.clear();
    dfsNumberCounter = 0;
    numSCC =0;
    //cout << "ttt" << st.size()<<'\n';
    for (auto i = 0; i < p; ++i) {
      string s;
      getline(cin, s);
      graph[s];
      dfs_num[s] = UNVISITED;
      dfs_low[s] = 0;
      visited[s] = 0;
    }
    for (auto i = 0; i < t; ++i) {
      string x, y;
      getline(cin , x);
      getline(cin , y);
      graph[x].insert(y);
    }
    for (auto& [u,v]:graph) {
      if (dfs_num[u] == UNVISITED) tarjanSCC(u);
    }
    cout << numSCC << '\n';
  }
  return 0;
}


