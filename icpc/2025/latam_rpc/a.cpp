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

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n; cin >> n;
  if (n!=2 and !(n&1)) {
    cout << "N\n";
    return 0;
  }
  vector<vector<bool>> mtx(n, vector<bool>(n,0));
  for (auto i = 0; i < n; i++) mtx[i][i]=1;
  int p, q; 
  int xd=-1, src=-1,tgt=-1; 
  int edg = n*(n-1)/2;
  bool can = 1;
  int fx, lx;
  fx=lx=-1;
  cin >> p;
  for (auto i = 0; i < p; i++) {
    int x; cin >> x; --x;
    if (i) { 
      --edg;
      if (mtx[x][xd]) {can=0;break;}
      mtx[x][xd]=1;
      mtx[xd][x]=1;
    } else fx = x;
    xd = x;
  }
  if (not can) { cout <<"N\n"; return 0; }
  src = xd;
  cin >> q;
  for (auto i = 0; i < q; i++) {
    int x; cin >> x; --x;
    if (i) { 
      --edg;
      if (mtx[x][xd]) {can=0;break;}
      mtx[x][xd]=1;
      mtx[xd][x]=1;
    } else tgt=x;
    xd = x;
  }
  lx = xd;
  if (not can) { cout <<"N\n"; return 0; }
  bool par_src=0, par_tgt=0;
  if (src == -1) swap(src, tgt);
  int imp = 0, par = 0;
  for (auto i = 0; i < n; i++) {
    int x = 0;
    for (auto j = 0; j < n; j++) 
      if (not mtx[i][j] and i!=j) ++x;
    if (i==src) par_src=!(x&1);
    if (i==tgt) par_tgt=!(x&1);
    if(i!=src and i!=tgt)(x&1)?++imp:++par;
  }
  if (src==-1 and tgt==-1) {
    cout << "Y\n";
    return 0;
  } else if (tgt ==-1) {
    if (par_src) can = imp==0;
    else can = imp==1;
  } else {
    if (src == tgt) can = par_src and par_tgt;
    else can = !par_src and !par_tgt;
    can &= imp==0;
    if (not edg) can = 0;
  }
  if (not can) { cout <<"N\n"; return 0; }
  vector<bool> vis(n);
  auto dfs = [&](auto&& self, int u) -> void{
    vis[u] =1;
    for (auto v = 0; v < n; v++) {
      if (!mtx[v][u]) --edg, mtx[v][u]=mtx[u][v]=1;
      if (!vis[v]) self(self, v);
    }
  };
  dfs(dfs,src);
  if (!edg) cout <<"Y";
  else cout <<"N";
  cout <<'\n';
  return 0;
}

