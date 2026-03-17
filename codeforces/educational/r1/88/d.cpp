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

vector<vi> adj;
vector<bool>vis, col;

pair<ll,ll> dfs(int u, int c) {
  vis[u]=1;
  col[u]=c;
  ll s = 1;
  ll z = c==0;
  for(auto& v: adj[u]) {
    if(not vis[v]) {
      auto [vs, vz] = dfs(v,c^1);
      s+=vs;
      z+=vz;
    }
    else if (col[v]==c) s=-1e9;
  } 
  return {s,z};
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt;cin>>tt;
  while(tt--) {
    int n,m;cin>>n>>m;
    vis.assign(n,0);
    col.assign(n,0);
    adj.assign(n,vi());
    for (auto i = 0; i < m; i++) {
      int a, b;cin>>a>>b;--a,--b;
      adj[a].emplace_back(b);
      adj[b].emplace_back(a);
    }
    ll ans = 0;
    for (auto i = 0; i < n; i++) {
      if (not vis[i]) {
        auto [s,z] = dfs(i,0);
        // dbg(s);
        // dbg(i);
        if(s>0)
          ans+=max(z,s-z);
      }
    }
    cout<<ans<<'\n';
  }
}

