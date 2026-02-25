#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int N, M; cin >> N>>M;
  vector<vi> g(N);
  for (auto i = 0; i < M; ++i) {
    int x,y; cin >> x >> y;
    g[x-1].push_back(y-1);
  }
  queue<int> q;
  q.push(0);
  int level=1, layer = 1;
  vi visited(N,0);
  while (not q.empty()) {
    int l = layer;
    layer = 0;
    for (auto i = 0; i < l; ++i) {
      int u = q.front(); q.pop();
      for(auto& v: g[u]) {
        if (v == 0) goto label;
        else if(not visited[v]) {
          ++layer;
          q.push(v);
          visited[v] = 1;
        }
      }
    }
    ++level;
  }
  cout << -1 << '\n';
  if (false) {
label:
    cout << level << '\n';
  } 
  return 0;
}


