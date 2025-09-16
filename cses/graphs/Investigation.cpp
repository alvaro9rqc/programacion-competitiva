#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vil = vector<pair<int,ll>>;
#define dbg(x) cerr << #x << " = " << (x) << endl;
#define raya cerr << " ==================== " << endl;
#define rep(i, a, b) for (auto i = a; i < (b); ++i)
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)

using li = pair<ll,int>;
int n, m;
vector<vil> adj;
vector<ll> dist;
vector<ll> memo;
const ll inf = ll(1e15);
ll mod = ll(1e9)+7;

ll dp(int u) {
  if (memo[u] !=-1) return memo[u];
  if (u == n-1) return 1;
  ll ans = 0;
  for(auto& [v,w]: adj[u]) {
    if (dist[u]+w==dist[v]) ans+=dp(v), ans%=mod;
  } 
  return memo[u]=ans;
}

int minf(int u){
  vector<bool> vis(n, 0);
  vis[u]=1;
  queue<int> qu;
  qu.emplace(u);
  int lev = 0;
  while(sz(qu)) {
    int lim = sz(qu);
    for (auto i = 0; i < lim; i++) {
      int v = qu.front(); qu.pop();
      if (v == n-1) return lev;
      for(auto& [x,w]: adj[v])  
        if (not vis[x] and dist[v]+w==dist[x]) 
          qu.emplace(x), vis[x]=1;
    }
    ++lev;
  }
  return -1;
}

ll maxf(int u){
  if (memo[u] != -1) return memo[u];
  if (u == n-1) return 1;
  ll ans = 0;
  for(auto& [v,w]: adj[u]) 
    if (dist[u]+w==dist[v]) ans=max(ans, maxf(v));
  if (ans) ++ans;
  return memo[u]=ans;
}


int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  cin >> n >> m;
  adj.assign(n, vil());
  for (auto i = 0; i < m; i++) {
    int a, b; ll c; cin >> a >> b >> c;
    --a,--b;
    adj[a].emplace_back(b, c);
  }
  priority_queue<li,vector<li>,greater<li>> pq;
  dist.assign(n, inf);
  dist[0]=0;
  pq.emplace(0,0);
  while(sz(pq)) {
    auto [d, u] = pq.top(); pq.pop();
    if (d > dist[u]) continue;
    for(auto& [v, w]: adj[u]) {
      if (dist[u]+w<dist[v]) {
        dist[v] = dist[u]+w;
        pq.emplace(dist[v], v);
      }
    } 
  }
  memo.assign(n, -1);
  auto x1 = dp(0);
  auto x2 = minf(0);
  memo.assign(n, -1);
  auto x3 = maxf(0);
  cout << dist[n-1] << ' '<<x1<<' '<<x2<<' '<<x3-1 <<'\n';
}

