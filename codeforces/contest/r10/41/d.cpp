#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
#define endl '\n'
#define dbg(x) cerr << #x << " = " << (x) << endl;
#define raya cerr << " ==================== " << endl;
#define rep(i, a, b) for (auto i = a; i < (b); ++i)
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)

struct UF {
	vi e;
	UF(int n) : e(n, -1) {}
  void init(int n){e.assign(n,-1);}
	bool sameSet(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
		return true;
	}
};

int n, m;
vector<vi> adj;
int cpa, cpb;
vector<bool> vis;
vl fac;
vi son;
UF uf(1);
ll mod = ll(1e9+7);
void load() {
  int cap = int(2e5+3);
  fac.assign(cap, 1);
  for (auto i = 1; i < cap; ++i) {
    fac[i] = fac[i-1]*i%mod;
  }
}

void dfs(int u, bool a) {
  vis[u] = 1;
  for(auto& v: adj[u]) {
    if (not vis[v]) dfs(v, a^1);
  }
  int cpc = a?cpa:cpb;
  for(auto& v: adj[u]) uf.join(cpc, v);
}

bool zz(int u, int xd){
  //if (not (0 <= u and u < n)) {
  //  cerr << u <<'\n';
  //  return 0;
  //}
  vis[u] = 1;
  int nod = 0;
  bool can = 1;
  for(auto& v: adj[u]) {
    if (not vis[v]) ++nod, can=zz(v, 1);
    if (not can) break;
  }
  son[u] = sz(adj[u]) - xd - nod;
  return nod+xd < 3 and can;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt; cin >> tt;
  load();
  while(tt--) {
    // reset all variables
    cin >> n >> m;
    adj.assign(n, vi());
    for (auto i = 0; i < m; ++i) {
      int x, y; cin >> x >> y;
      --x,--y;
      adj[x].emplace_back(y);
      adj[y].emplace_back(x);
    }
    uf.init(n);
    // bip
    cpa = 0;
    cpb = adj[0][0];
    vis.assign(n,0);
    dfs(0, 0);
    if (uf.sameSet(cpa, cpb)) {
      cout << 0 << '\n'; continue;
    } 
    int nodes = 0;
    int org = -1;
    for (auto i = 0; i < n; ++i) {
      if (sz(adj[i]) > 1) ++nodes, vis[i] = 0, org = i;
    }
    if (nodes == 1 or org == -1) {
      ll ans = fac[n-1] << 1;
      ans%=mod;
      cout << ans <<'\n';
      continue;
    }
    son.assign(n, 0);
    // asfasd
    bool val = 1;
    int ext = 0;
    for (auto i = 0; i < n; ++i) {
      if (vis[i]) continue;
      int nei = 0;
      for(auto& u: adj[i]) 
        if (not vis[u]) ++nei;
      if (nei > 2) {val = 0; break;}
      son[i] = sz(adj[i]) - nei;
      if (nei == 1) ++ ext;
    }
    if (not val or ext != 2) {
      cout << 0 << '\n';
    } else {
      ll ans = 4;
      for(auto& e: son) ans*=fac[e], ans%=mod;
      //for(auto& e: son) cout << e << ' ';
      //cout << "ex\n";
      cout << ans << '\n';
    }
  }
}
