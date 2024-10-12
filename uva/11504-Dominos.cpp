#include <bits/stdc++.h> 
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
enum { UNVISITED = -1 };

int numSCC;
vi dfs_num;
vector<vi> graph, graphT;
vi st;

void Kosaraju(int u, int pass) {
  dfs_num[u] = 1;
  vi& neighbor = (pass == 1) ? graph[u] : graphT[u];
  for (auto& v : neighbor)
    if (dfs_num[v] == UNVISITED) Kosaraju(v, pass);
  st.push_back(u);
}

int main () {
  ios_base::sync_with_stdio(false);
  int n, t, x, y,m;
  cin >> t;
  while (t--) {
    cin >> n>> m;
    st.clear();
    graph.assign(n, vi());
    graphT.assign(n, vi());
    for (auto i = 0; i < m; ++i) {
      cin >> x >> y;
      --x; --y;
      //cout << x << ' '<<y<<'\n';
      graph[x].push_back(y);
      graphT[y].push_back(x);
    }
    //for (auto i = 0; i < graph.size(); ++i) {
    //  for (auto j = 0; j < graph[i].size(); ++j) {
    //    cout << graph[i][j] << ' ';
    //  }
    //  cout << '\n';
    //}
    dfs_num.assign(n, UNVISITED);
    for (int i = 0; i < n; ++i) {
      if (dfs_num[i] == UNVISITED) 
        Kosaraju(i, 1);
    }
    numSCC = 0;
    dfs_num.assign(n, UNVISITED);
    //for (auto i = 0; i < st.size(); ++i) {
    //  cout << st[i] << ' ';
    //}
    //cout << '\n';
    for (int i = n-1; i >= 0; --i) {
      if (dfs_num[st[i]] == UNVISITED) {
        //bool f = true;
        //for (auto& i : graphT[ st[i] ]) {
        //  if (dfs_num[i] != UNVISITED) f = false;
        //}
        //if (f) ++ numSCC;
        //if(graphT[ st[i] ].size() == 0) ++numSCC;
        ++numSCC;
        Kosaraju(st[i], 1);
      }
    }
    cout << numSCC << '\n';
  }
  return 0;
}


