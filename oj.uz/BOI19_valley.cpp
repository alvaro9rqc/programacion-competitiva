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

int n, s, q, e, lim = 17;
ll inf = ll(1e16);
using par = pair<int,ll>;
vector<vector<par>> adj;
vector<bool> vis, ist;
vi inp, out, niv;
vl dist, mag;
vector<vector<par>> miele;

void gaaa(int u, int& t, int p, ll d, int lev) {
  inp[u] = t;
  miele[0][u] = {p, 0};
  niv[u] = lev;
  dist[u] = d;
  for(auto& [v, w]: adj[u]) {
    if (inp[v] >= 0) continue;
    gaaa(v, ++t, u, d+w, lev+1);
  }
  out[u] = t++;
}

bool anc(int u, int v) {
  return inp[u] <= inp[v] and out[v] <= out[u];
}

ll magico(int u) {
  vis[u] = 1;
  for(auto& [v,w]: adj[u]) {
    if (vis[v])continue;
    mag[u] = min(mag[u], magico(v) + 2*w);
  }
  if (ist[u]) mag[u] = -dist[u];
  return mag[u];
}

void here() {
  for (auto i = 0; i < n; i++) {
    auto [p, m] = miele[0][i];
    //miele[0][i].second = min(mag[i], mag[p]);
    miele[0][i].second = mag[p];
  }
  for (auto i = 1; i < lim; i++) {
    for (auto j = 0; j < n; j++) {
      miele[i][j] = { miele[i-1][miele[i-1][j].first].first,  
        min(miele[i-1][j].second, miele[i-1][miele[i-1][j].first].second)
      };
    }
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  cin >> n >> s >> q >> e;
  vector<ii> edg(n);
  --e;
  adj.assign(n, vector<par>());
  ist.assign(n,0);
  vis.assign(n,0);
  inp.assign(n, -1);
  out.assign(n, 0);
  niv.assign(n, 0);
  dist.assign(n, 0);
  mag.assign(n, inf);
  miele.assign(lim, vector<par>(n));
  for (auto i = 0; i < n-1; i++) {
    int x,y; ll w; cin >> x >> y >> w;
    --x,--y;
    edg[i]={x,y};
    adj[x].emplace_back(y, w);
    adj[y].emplace_back(x, w);
  }
  for (auto i = 0; i < s; i++) {int x; cin >> x; ist[x-1]=1;}
  int xd = 0;
  gaaa(e, xd, e, 0, 0);
  magico(e);
  here();
  adj.clear();
  for (auto q_ = 0; q_ < q; q_++) {
    int x, y; cin >> x >> y;
    --x, --y;
    int p =(inp[edg[x].first]> inp[edg[x].second])?edg[x].first:edg[x].second;
    if (anc(p, y)) {
      int d = niv[y] - niv[p];
      ll m = mag[y];
      xd = y;
      for (auto i = 0; i < lim; i++) 
        if (d & 1<<i) 
          m = min(m, miele[i][y].second), y = miele[i][y].first;
      if (m == inf) cout << "oo\n";
      else cout << m + dist[xd]<<'\n';
    } else {
      cout << "escaped\n";
    }
  }
  //for(auto& i: mag) cout <<i<<' '; cout << '\n';
  //for(auto& [v,w]: miele[0]) cout << v<<'.'<<w<<' ';cout <<'\n';
}


