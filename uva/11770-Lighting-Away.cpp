#include <bits/stdc++.h> 
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
enum{ UNVISITED=-1 };

vector<vi> graph;
int numSCC;
vi dfs_num;
vi st;

void Kosaraju(int u) {
  dfs_num[u] = 1;
  for(auto& v:graph[u] )
    if (dfs_num[v] == UNVISITED) Kosaraju(v);
  st.push_back(u);
}

int main () {
  ios_base::sync_with_stdio(false);
  int t, n,m,x,y;
  cin >> t;
  int counter = 0;
  while (counter++<t) {
    cin >> n >> m;
    st.clear();
    graph.assign(n,vi());
    for (auto i = 0; i < m; ++i) {
      cin >> x >> y;
      --x;--y;
      graph[x].push_back(y);
    }
    dfs_num.assign(n, UNVISITED);
    for (auto i = 0; i < n; ++i) {
      if (dfs_num[i] == UNVISITED)Kosaraju(i);
    }
    numSCC=0;
    dfs_num.assign(n,UNVISITED);
    for (auto i = n-1; i >= 0; --i) {
      if(dfs_num[ st[i] ] == UNVISITED)
      {
        ++numSCC;
        Kosaraju(st[i]);
      }
    }
    cout <<"Case "<<counter<<": "<< numSCC<<'\n';
  }
  return 0;
}


