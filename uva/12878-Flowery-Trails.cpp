#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
ll sum = 0;

const ll INF = LLONG_MAX;
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll P, T;
  while (cin >> P >> T) {
    vector<vector<pair<ll,ll>>> g(P, vector<pair<ll,ll>>());
    for (ll i = 0; i < T; ++i) {
      int p1, p2, l;
      cin >> p1 >> p2 >> l;
      if (p1 == p2) continue;
      g[p1].emplace_back(p2, l);
      g[p2].emplace_back(p1, l);
    }
    vector<ll> dist(P, INF);
    vector<ll> edges(P, 0);
    vector<vi> origin(P, vi());
    sum = 0;
    dist[0] = 0;
    priority_queue<tuple<ll, ll,ll,ll>, vector<tuple<ll, ll,ll,ll>>, greater<tuple<ll,ll, ll,ll>>>pq;
    pq.emplace(0, 0, 0,0);
    while(!pq.empty()) {
      auto [d, u, e, o] = pq.top(); pq.pop();
      if (d > dist[u]) continue;
      edges[u] += e;
      origin[u].push_back(o);
      if (origin[u].size() != 1) continue;
      for(auto& [v, w]: g[u]) {
        //cout << v << ' ' << w <<" : " << u << '\n';
        if (w + dist[u] > dist[v]) continue;
        dist[v] = w + dist[u];
        pq.emplace(dist[v], v, w, u);
      }
    }
    //cout <<"--> "<< dist[P-1]<<'\n';
    set<int> vis;
    queue<int> path;
    path.push(P-1);
    vis.insert(P-1);
    while (! path.empty()) {
      int v = path.front(); path.pop();
      //cout << "e: " << v << " w: " << edges[v]<<'\n';
      sum += edges[v];
      for(auto& u: origin[v]) {
        if (vis.find(u) != vis.end()) continue;
        vis.insert(u);
        path.push(u);
      }
    }
    cout << 2 * sum << '\n';
  }
  return 0;
}


