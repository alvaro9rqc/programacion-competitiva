#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

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
      g[p1].emplace_back(p2, l);
      g[p2].emplace_back(p1, l);
    }
    vector<ll> dist(P, INF);
    vector<ll> acum(P, 0);
    dist[0] = 0;
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>>pq;
    pq.emplace(0, 0);
    while(!pq.empty()) {
      auto& [d, u, ac] = pq.top(); pq.pop();
      if (d > dist[u]) continue;
      //if (d == dist[u]) acum[u]+= e;
      set<int> s;
      for(auto& [w, v]: g[u]) {
        if (w + dist[u] == dist[v]) 
        {
          if (s.find(v) == s.end()) {
            acum[v] += acum[u];
            s.insert(v);
          }
          acum[v] += w;
        }
        if (w + dist[u] >= dist[v]) continue;
        dist[v] = w + dist[u];
        acum[v] = w + acum[u];
        pq.emplace(w, u, b);
      }
    }
  }
  return 0;
}


