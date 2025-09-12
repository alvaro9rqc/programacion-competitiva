#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
#define dbg(x) cerr << #x << " = " << (x) << endl;
#define raya cerr << " ==================== " << endl;
#define rep(i, a, b) for (auto i = a; i < (b); ++i)
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)


using vil = vector<pair<int, ll>>;
ll inf = ll(1e6);

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n, m;
  while(cin >> n >> m) {
    if (n == 0 and m == 0) break;
    vector<vil> adj(n);
    for (auto i = 0; i < m; i++) {
      int u, v; ll w; cin >>u>>v >>w;
      w=-w;
      --u,--v;
      adj[u].emplace_back(v, w);
    }
    vl dis(n, inf);
    dis[0] = 0;
    for (auto i = 0; i < n; i++) {
      bool mod = 0;
      for (auto u = 0; u < n; u++) 
        if (dis[u]!=inf) {
          for(auto& [v,w]: adj[u]) {
            ll d = dis[u]+w;
            if (d < dis[v]) {
              dis[v] = (i < n-1?d:-inf);
              mod = 1;
            }
          }
        }
      if (not mod) break;
    }
    ll ans = inf;
    for(auto& d: dis) ans = min(ans, d);
    if (ans == -inf) cout << "Unlimited!";
    else cout << -ans;
    cout <<'\n';
  }
}

