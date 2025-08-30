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
vector<vi> adj;
vi inp, out;
vector<bool> vis;
vi par;
vector<vi> ancestors;

bool anc(int u, int v) {
  return inp[u] <= inp[v] and out[v] <= out[u];
}

int lca(int u, int v) {
  if (anc(u,v)) return u;
  if (anc(v,u)) return v;
  //cout << u <<' ' << v <<'\n'; 
  for (auto i = 14; i >= 0; i--) {
    if (not anc(ancestors[u][i], v)) u = ancestors[u][i]
      //cerr<<": "<<u<<'\n';
      ;
  }
  return par[u];
}

vi st;
void dfs(int u, int& t, int lev) {
  st[lev]=u;
  for (auto i = 0; (1<<(i)) < lev+1; i++) ancestors[u][i] = (st[lev-(1<<(i))]);
  vis[u] = 1;
  inp[u] = t;
  for(auto& v: adj[u]) {
    if (not vis[v]) {
      dfs(v, ++t, lev+1);
    }
  }
  out[u]=t++;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  cin >> n;
  adj.assign(n, vi());
  par.assign(n, 0);
  for (auto i = 0; i < n; i++) {
    int x; cin >> x;
    adj[i].resize(x);
    for (auto j = 0; j < x; j++) 
      cin >> adj[i][j], par[adj[i][j]]=i;
  }
  int qq; cin >> qq;
  inp.assign(n, 0);
  out.assign(n, 0);
  vis.assign(n, 0);
  int xd =0;
  st.assign(n,0);
  ancestors.assign(n,vi(15, 0));
  dfs(0, xd, 0);
  //dbg(anc(1,11));
  //for(auto& r: ancestors) 
    //for(auto& c: r) cout << c << (&c == &r.back()?'\n':' ');
  //for(auto& i: inp) cout << i << (&i == &inp.back()?'\n':' ');
  //for(auto& i: out) cout << i << (&i == &out.back()?'\n':' ');
  //for(auto& i: par) cout << i << (&i == &par.back()?'\n':' ');
  //for (auto i = 0; i < n; i++) cout << vis[i]<<' '; cout <<'\n';
  for (auto q = 0; q < qq; q++) { 
    int x, y; cin >> x >>y;
    cout << lca(x,y)<<'\n';
  }
}


