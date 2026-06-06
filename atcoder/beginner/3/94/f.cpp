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

vector<vector<ii>> memo;
vector<vector<ii>> hlp;
vector<vi> adj1,adj;

void dfs(int u, int p) {
  for(auto& v: adj1[u]) {
    if(v!=p) {
      adj[u].emplace_back(v);
      dfs(v,u);
    }
  } 
}

pair<int,bool> dp(bool c, int u) {
  if(memo[c][u].first!=-2) return memo[c][u];
  auto& [ans,l] = memo[c][u];
  if(!sz(hlp[u])){
    for(auto& v: adj[u]) hlp[u].emplace_back(dp(1,v));
    sort(all(hlp[u]));
    reverse(all(hlp[u]));
  }
  if(c) {
    ans=1;
    l=0;
    if(sz(hlp[u])>=3) {
      for (auto i = 0; i < 3; i++) ans+=hlp[u][i].first;
      l=1;
    }
  } else {
    ans=-1;
    if(sz(hlp[u])>=4){
      ans=1;
      for (auto i = 0; i < 4; i++) ans+=hlp[u][i].first;
      l=1;
    } else {
      for(auto& [v,lj]: hlp[u]) if(lj)ans=max(ans,1+v),l=1;
    }
  }
  return {ans,l};
}

void solve() {
  int n;cin>>n;
  adj.assign(n, vi());
  adj1.assign(n, vi());
  memo.assign(2, vector<ii>(n,{-2,0}));
  hlp.assign(n, vector<ii>());
  for (auto i = 0; i < n-1; i++) {
    int u,v;cin>>u>>v;
    --u,--v;
    adj1[u].emplace_back(v);
    adj1[v].emplace_back(u);
  }
  dfs(0,0);
  int ans = -1;
  for (auto i = 0; i < n; i++) {
    auto [p,l] = dp(0,i);
    if(l)ans=max(p,ans);
  }
  cout<<ans<<'\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt=1;
  // cin>>tt;
  while(tt--) {
    solve();
  }
}

