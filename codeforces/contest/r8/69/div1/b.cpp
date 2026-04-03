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

int n, u, leaf, last;
vector<ii> ans;
vector<vi> adj;
vector<bool> vis;

bool dfs(int v, int p) {
  vis[v]=1;
  for(auto& x: adj[v]) {
    if(x==u and u!=p) {
      leaf=v;
      ans.emplace_back(v,u);
      return 1;
    } else {
      if(vis[x]) continue;
      auto a = dfs(x,v);
      if(a) {
        ans.emplace_back(v,x);
        last=x;
        return 1;
      }
    }
  }
  return 0;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt;cin>>tt;
  while(tt--) {
    int m;cin>>n>>m;
    adj.assign(n,vi());
    ans.resize(0);
    for (auto i = 0; i < m; i++) {
      int x,y;cin>>x>>y;
      --x,--y;
      adj[x].emplace_back(y);
      adj[y].emplace_back(x);
    }
    bool can=0;
    for (auto i = 0; i < n; i++) {
      vis.assign(n,0);
      u=i;
      if(sz(adj[i])>=4 and dfs(i,i)) {
        int xd = 0;
        for(auto& x: adj[i]) 
        if(x!=leaf and x!=last and xd!=2) ans.emplace_back(i,x),++xd;
        cout<<"YES\n";
        cout<<sz(ans)<<'\n';
        for(auto& [a,b]: ans) cout<<a+1<<' '<<b+1<<'\n';
        can=1;
        break;
      }
    }
    if(!can)cout<<"NO\n";
  }
}

