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

void solve() {
  int n,q;cin>>n>>q;
  vi col(n),par(n), edg(n);
  vector<vector<ii>> adj(n,vector<ii>());
  vector<unordered_map<int,ll>> son(n, unordered_map<int,ll>());
  for(auto& i: col) cin >> i;
  for (auto i = 0; i < n-1; i++) {
    int u,v,w;cin>>u>>v>>w;
    --u,--v;
    adj[u].emplace_back(v,w);
    adj[v].emplace_back(u,w);
  }
  queue<int> que;
  par[0]=0;
  que.emplace(0);
  ll ans = 0;
  while(sz(que)) {
    auto u = que.front(); que.pop();
    for(auto& [v,w]: adj[u]) {
      if(par[u]==v)continue;
      if(col[u]!=col[v])ans+=w;
      son[u][col[v]]+=w;
      que.emplace(v);
      par[v]=u;
      edg[v]=w;
    }
  }
  for (auto _ = 0; _ < q; _++) {
    int u,x;cin>>u>>x;
    --u;
    // son
    auto it = son[u].find(col[u]);
    if(it!=son[u].end()) ans+=it->second;
    it = son[u].find(x);
    if(it!=son[u].end()) ans-=it->second;
    // par
    if(u!=0) {
      auto v = par[u];
      if(col[v]==col[u])ans+=edg[u];
      it = son[v].find(col[u]);
      it->second-=edg[u];
      if(it->second==0)son[v].erase(it);
      son[v][x]+=edg[u];
      if(col[v]==x)ans-=edg[u];
    }
    col[u]=x;
    cout<<ans<<'\n';
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt=1;
  cin>>tt;
  while(tt--) {
    solve();
  }
}

