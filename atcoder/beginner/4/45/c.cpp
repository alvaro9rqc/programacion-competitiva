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

vi vis, idtcic, dist, pos, adj;
vector<vi> cont;

void dfs2(int i) {
  idtcic[i]=sz(cont)-1;
  int u = adj[i];
  pos[i]=sz(cont.back());
  cont.back().emplace_back(i);
  if (idtcic[u]==-1) dfs2(u);
}

void dfs1(int i, int t, int id) {
  vis[i]=id;
  dist[i]=t;
  int u = adj[i];
  if (vis[adj[i]]==-1) dfs1(adj[i], t+1, id);
  else if (vis[u]==id) cont.emplace_back(), dfs2(i);
}

void dfs3(int i) {
  int u = adj[i];
  if (pos[u]==-1) dfs3(u);
  pos[i]=pos[u];
  idtcic[i]=idtcic[u];
  dist[i]=1+dist[u];
}

ll ex(ll c) {
  ll b = 10;
  int e = 100;
  ll r=1;
  while(e){
    if (e&1) { r*=b; r%=c;}
    b*=b; b%=c;
    e>>=1;
  }
  return r;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n;cin>>n;
  vis.assign(n,-1);
  idtcic.assign(n,-1);
  pos.assign(n,-1);
  adj.resize(n); for(auto& i: adj) cin>>i, --i;
  dist.assign(n,0);
  for (auto i = 0; i < n; i++) {
    if (vis[i]==-1) dfs1(i, 0, i);
  }
  dist.assign(n,0);
  for (auto i = 0; i < n; i++) {
    if (pos[i]==-1) dfs3(i);
    int s = sz(cont[idtcic[i]]);
    cout<<(cont[idtcic[i]][ (s+(ex(s)-dist[i])%s)%s ]+1)<<' ';
  }
  cout<<'\n';
}


