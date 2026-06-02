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
  vector<vi> adj;
  int n,m;cin>>n>>m;
  adj.assign(n,vi());
  for (auto i = 0; i < m; i++) {
    int u,v;cin>>u>>v;
    --u,--v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }
  for (auto i = 0; i < n; i++) {
    if(sz(adj[i])<4)continue;
    vector<ii> ans;
    vi p(n),vis(n,0),pxd(n);
    p[i]=i;
    auto f = [&](int u) {
      int l = u;
      while(u!=i) {
        ans.emplace_back(u, p[u]);
        l=u;u=p[u];
      }
      return l;
    };
    queue<int> que;
    // que.emplace(i,i);
    vis[i]=1;
    for(auto& u: adj[i]) {
      que.emplace(u);
      vis[u]=1;
      p[u]=i;
      pxd[u]=u;
    }
    int c1=-1,c2=-1;
    while (sz(que) and c1==-1) {
      auto u = que.front(); que.pop();
      for(auto& v: adj[u]) {
        if(not vis[v]) que.emplace(v),vis[v]=1,p[v]=u,pxd[v]=pxd[u];
        else if(pxd[v]!=pxd[u] and v!=i) {
          ans.emplace_back(v,u);
          c1=f(u);
          c2=f(v);
          break;
        }
      }
    }
    if(c1==-1)continue;
    int xd=0;
    for (auto j = 0; j < sz(adj[i]) and xd!=2; j++) {
      if(adj[i][j]!=c1 and adj[i][j]!=c2) ++xd,ans.emplace_back(i,adj[i][j]);
    }
    cout<<"YES\n";
    cout<<sz(ans)<<'\n';
    for(auto& [u,v]: ans) cout<<u+1<<' '<<v+1<<'\n';
    return;
  }
  cout<<"NO\n";
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt;cin>>tt;
  while(tt--) {
    solve();
  }
}

