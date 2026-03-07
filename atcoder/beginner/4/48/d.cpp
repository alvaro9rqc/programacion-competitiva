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
vl label;
map<ll,ll>rep;
set<ll>mt2;
vector<bool> ans,vis;
vector<vi>adj;


void dfs(int i) {
  vis[i]=1;
  if (++rep[label[i]]>1)mt2.emplace(label[i]);
  ans[i]=sz(mt2);
  for(auto& v: adj[i]) {
    if (not vis[v]) dfs(v);
  }
  if(--rep[label[i]]<2)mt2.erase(label[i]);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  cin>>n;
  label.assign(n,0);
  adj.assign(n,vi());
  vis.assign(n,0);
  ans.assign(n,0);
  for(auto& i: label) cin>>i;
  for (auto i = 0; i < n-1; i++) {
    int u,v;cin>>u>>v;
    --u,--v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }
  dfs(0);
  for (auto i = 0; i < n; i++) cout<<(ans[i]?"Yes":"No")<<'\n';
}

