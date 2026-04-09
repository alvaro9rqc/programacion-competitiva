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

int n;
vector<vi> adj_4,adj;
vi dp;

int dfs(int u, int p) {
  if(dp[u]!=-1)return dp[u];
  if(sz(adj_4[u])<4)return dp[u]=0;
  dp[u]=1;
  vi alt;
  for(auto& v: adj[u]) {
    if(v==p)continue;
    alt.emplace_back(dfs(v,u));
  }
  sort(alt.rbegin(), alt.rend());
  for (auto i = 0; i < min(3,sz(alt)); i++) dp[u]+=alt[i];
  return dp[u];
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  cin>>n;
  adj_4.assign(n,vi());
  adj.assign(n,vi());
  dp.assign(n,-1);
  for (auto i = 0; i < n-1; i++) {
    int x,y;cin>>x>>y;--x,--y;
    adj_4[x].emplace_back(y);
    adj_4[y].emplace_back(x);
  }
  for (auto i = 0; i < n; i++) {
    if(sz(adj_4[i])<4)continue;
    for(auto& v: adj_4[i]) {
      if(sz(adj_4[v])>=4) adj[i].emplace_back(v);
    }
  }
  int ans = 0;
  for (auto i = 0; i < n; i++) {
    ans=max(ans,dfs(i,i));
  }
  cout<<(ans?ans*3+2:-1)<<'\n';
}

