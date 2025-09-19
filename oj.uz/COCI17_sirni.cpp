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

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n; cin >> n;
  using vii = vector<ii>;
  vector<vii> adj(n);
  map<int,int> ids;
  for (auto i = 0; i < n; i++) {
    int x; cin >> x;
    if (not ids.count(x)) ids[x]=sz(ids);
  }
  while(sz(ids)) {
    auto it = ids.begin();
    auto [p, u] = *it;
    ids.erase(it);
    auto key = p;
    while(1) {
      it = ids.lower_bound(key);
      if (it == ids.end()) break;
      key=it->first;
      int v = it->second;
      int w = key%p;
      adj[u].emplace_back(v, w);
      adj[v].emplace_back(u, w);
      key += p - key%p;
    }
  }
  //for(auto& nei: adj) {
  //  for(auto& [v, w]: nei) cout << v <<","<<w<<"   " <<' ';
  //  cout <<'\n';
  //}
  ll ans = 0;
  priority_queue<ii, vii, greater<ii>> pq;
  vector<bool> used(n, 0);
  int inf = int(1e8);
  vi dist(n, inf);
  pq.emplace(0, 0);
  int taken = 0;
  dist[0] = 0;
  while(sz(pq)) {
    auto [d, u] = pq.top(); pq.pop();
    if (used[u]) continue;
    used[u] = 1;
    ++taken;
    ans+= d;
    if (taken == n) break;
    for(auto& [v, w]: adj[u]) {
      if (not used[v] and w < dist[v]) {
        pq.emplace(w, v);
        dist[v]=w;
      }
    } 
  }
  cout << ans <<'\n';
}

