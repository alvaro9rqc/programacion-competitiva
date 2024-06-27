#include <bits/stdc++.h> 
#define INF  (int)1e9*2
using namespace std;

void dijkstra(vector<vector<int>>& g, int& ex, int& t) {
  vector<int> dist(g.size(), INF);
  dist[ex] = 0;
  set <pair<int,int>> pq;
  for (int i = 0; i < g.size(); i++) {
    pq.emplace(dist[i], i); 
  }
  while(! pq.empty()) {

  }
}
int main () {
  ios_base::sync_with_stdio(false);
  int tests, n, t, ex, m, a, b;
  cin >> tests;
  while (tests--) {
    cin >> n >> ex >> t >> m;
    vector< vector<int> > graph(n, vector<int>());
    while (m --) {
      cin >> a >> b;
      graph[b].push_back(a);
    }
  }
  return 0;
}


