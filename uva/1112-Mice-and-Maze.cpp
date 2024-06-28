#include <bits/stdc++.h> 
#define INF  (int)1e9*2
using namespace std;

void dijkstra(vector<vector<pair<int,int>>>& g, int& ex, int& t) {
  vector<int> dist(g.size(), INF);
  dist[ex] = 0;
  set <pair<int,int>> pq;
  int n = 0;
  for (int i = 0; i < g.size(); i++) {
    pq.emplace(dist[i], i); 
  }
  while(! pq.empty()) {
    auto [d, u] = * pq.begin();
    pq.erase(pq.begin());
    if (d > t) break;
    ++n;
    for (auto& [v, w] : g[u]) {
      if (dist[u] + w >= dist[v]) continue;
      pq.erase(pq.find({dist[v], v}));
      dist[v] = dist[u] + w;
      pq.emplace(dist[v], v);
    }
  }
  cout << n << "\n";
}
int main () {
  ios_base::sync_with_stdio(false);
  int tests, n, t, ex, m, a, b, w;
  cin >> tests;
  while (tests--) {
    cin >> n >> ex >> t >> m;
    vector< vector<pair<int, int>> > graph(n, vector<pair<int,int>>());
    while (m --) {
      cin >> a >> b >> w;
      graph[--b].push_back({--a, w});
    }
    dijkstra(graph, --ex, t);
    if (tests != 0) cout << '\n';
  }
  return 0;
}


