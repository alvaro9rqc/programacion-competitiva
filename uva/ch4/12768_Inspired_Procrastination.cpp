#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vl;
#define dbg(x) cerr << #x << " = " << (x) << endl;
#define raya cerr << " ==================== " << endl;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

typedef vector<pair<int, ll> > vil;
ll inf = ll(1e6);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin.exceptions(cin.failbit);

  int n, m;
  while (cin >> n >> m) {
    if (n == 0 && m == 0) break;
    vector<vil> adj(n);
    for (int i = 0; i < m; i++) {
      int u, v; ll w; 
      cin >> u >> v >> w;
      w = -w;
      --u; --v;
      adj[u].push_back(make_pair(v, w));
    }
    vl dis(n, inf);
    dis[0] = 0;
    for (int i = 0; i < n; i++) {
      bool mod = false;
      for (int u = 0; u < n; u++) {
        if (dis[u] != inf) {
          for (size_t j = 0; j < adj[u].size(); j++) {
            int v = adj[u][j].first;
            ll w = adj[u][j].second;
            ll d = dis[u] + w;
            if (d < dis[v]) {
              dis[v] = (i < n - 1 ? d : -inf);
              //dis[v] = d;
              mod = true;
            }
          }
        }
      }
      if (!mod) break;
    }
    bool neg = 0;
    for (auto u = 0; u < n; u++) 
      if (dis[u]!=inf)
        for (size_t j = 0; j < adj[u].size(); j++) {
          int v = adj[u][j].first;
          ll w = adj[u][j].second;
          ll d = dis[u] + w;
          if (d < dis[v]) {
            //dis[v] = (i < n - 1 ? d : -inf);
            neg = true;
          }
        }
    ll ans = inf;
    for (size_t i = 0; i < dis.size(); i++) {
      ans = min(ans, dis[i]);
    }
    if (ans==-inf) cout << "Unlimited!";
    else cout << -ans ;
    cout << '\n';
  }
}

