#include <bits/stdc++.h> 
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
enum { UNV = -1 };

vi dfs_num;
vector<vi>graph;
stack<int> st;

int dfs(int v) {
  int sum = 1;
  dfs_num[v] = 1;
  for(auto& u: graph[v]) {
    if (dfs_num[u]==UNV)
      sum += dfs(u);
  }
  return sum;
}

void postorden(int u) {
  dfs_num[u] = 1;
  for(auto& i: graph[u]) {
    if (dfs_num[i] == UNV)
      postorden(i);
  }
  st.push(u);
}

int main () {
  ios_base::sync_with_stdio(false);
  int t, x,y,n;
  int counter = 0;
  cin >> t;
  while (counter++ < t) {
    cin>>n;
    graph.assign(n,vi());
    dfs_num.assign(n,UNV);
    for (auto i = 0; i < n; ++i) {
      cin>>x>>y;
      --x;--y;
      graph[x].push_back(y);
    }
    for (auto i = 0; i < n; ++i) {
      if (dfs_num[i] == UNV)
        postorden(i);
    }
    int size=0;
    int ver = n;
    dfs_num.assign(n, UNV);
    while(! st.empty()) {
      int v = st.top(); st.pop();
      if (dfs_num[v] == UNV) {
        int tam = dfs(v);
        if (tam >= size) 
        {
          ver = v;
          size = tam;
        }
      }
    }
    cout << "Case " << counter<<": "<<ver+1<<'\n';
  }
  return 0;
}


