#include <bits/stdc++.h> 
#define INF (int)1e9*2
using namespace std;

void dijkstra (vector<vector<pair<int, int>>>& g, int& t, int& s) {
  //cout << "para: " << t << " " << s << '\n';
  vector<int> dist(g.size(), INF);
  dist[t] = 0;
  set <pair<int, int>> pq;
  int total = -1;
  for (int i = 0; i < g.size(); i++) 
    pq.emplace(dist[i], i);
  while (! pq.empty()) {
    auto [d, u] = *pq.begin();
    pq.erase(pq.begin());
    //cout << "\nmin: " << u << " " << d << "->" << s<<'\n';
    if (d == INF) break;
    if (u == s) {
      //cout << "reach\n";
      total = d;
      break;
    }
    for (auto&[v, w] : g [u]) {
      //cout << "veet: " << v << " " << w << '\n';
      if (dist[u] + w >= dist[v]) continue;
      pq.erase(pq.find( {dist[v], v} ));
      dist[v] = dist[u] + w;
      pq.emplace(dist[v], v);
    }
  }
  if (total == -1) cout << "unreachable" << '\n';
  else cout << total << '\n';
}

int main () {
  ios_base::sync_with_stdio(false);
  int N, n, m, t, s, a, b, w;
  cin >> N;
  int i = 1;
  while (i <= N) {
    cin >> n >> m >> t >> s;
    vector< vector< pair<int, int> > > graph(n, vector<pair<int,int>>());
    while (m--) {
      cin >> a >> b >> w;
      graph[a].push_back( {b, w} );
      graph[b].push_back( {a, w} );
    }
    cout << "Case #" << i++ << ": ";
    dijkstra(graph, s, t);

  }
  return 0;
}


