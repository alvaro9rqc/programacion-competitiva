#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const ll INF = 90000000;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,m,b,p;
  while (cin >> n >> m >> b >>p) {
    vector<vii> g(n, vii());
    for (auto i = 0; i < m; ++i) {
      int u, v, w;
      cin >> u >> v >> w;
      g[u].emplace_back(v,w);
      g[v].emplace_back(u,w);
    }
    vector<pair<int, ll>> banks(b);
    set<int> pol;
    for (auto i = 0; i < b; ++i) {
      int x; cin >> x;
      banks[i] = {x, INF};
    }
    sort(banks.begin(), banks.end());
    for (auto i = 0; i < p; ++i) {
      int x; cin >> x;
      pol.insert(x);
    }
    ll maxdist=-1;
    ll count = 0;
    for(auto& [b, d]: banks) {
      //Dijsktra
      vector<ll> dist(n,INF);
      priority_queue<pair<ll, ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
      pq.emplace(0,b);
      dist[b] = 0;
      while(!pq.empty()) {
        auto [w0, v] = pq.top(); pq.pop();
        if (w0 > dist[v]) continue;
        if (pol.find(v) != pol.end()) {
          d = w0;
          break;
        }
        for(auto& [u, w]: g[v]) {
          if (dist[u] <= w + dist[v]) continue;
          dist[u] = w + dist[v];
          pq.emplace(dist[u], u);
        }
      }
      if (d == maxdist) count++;
      if (d > maxdist) {
        count = 1;
        maxdist = d;
      }
    }
    cout << count << ' ';
    if (maxdist == INF) cout << "*\n";
    else cout << maxdist << '\n';
    bool f = true;
    for(auto& [b, d]: banks) {
      if (d == maxdist) 
      {
        if (f)
          cout << b;
        else 
          cout << ' ' << b;
        f = false;
      }
    }
    cout << '\n';
  }
  return 0;
}


