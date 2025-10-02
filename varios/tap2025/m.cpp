#include<bits/stdc++.h>
#define rep(i, a, b) for (auto i = a; i <(b); ++i)
#define sz(x) (int)(x).size()
#define dbg(x) cerr << #x <<"="<< (x) <<'\n';
#define raya cerr << "=======================\n";


using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;


vector<vector<vi>> memo;
vi dist;
int n, m, k;
int inf = int(1e7);
vector<vi> adj;
int dias;
int mod = 998244353;

inline bool can(int u, int d, int p) {
	return dist[u] - (k - p) <= (dias - d-1) * k;
}

int dp(int u, int d, int p) {
	if (memo[u][d][p] != -1) return memo[u][d][p];
	int ans = (u == 1);
	if (p < k) {
		for(auto& v: adj[u]) {
			if (can(v, d, p+1)) ans += dp(v, d, p+1), ans%=mod;
		}
	}
	if (d+1 < dias) {
		for(auto& v: adj[u]) {
			//raya;
			if (can(v, d+1, 1)) ans += dp(v, d+1, 1), ans%=mod;
		}
	}
	//dbg(u);
	//dbg(d);
	//dbg(p);
	//dbg(ans);
	return memo[u][d][p]=ans;
}

int main() {
	cin >> n >> m >> k;
	dist.assign(n, inf);
	adj.assign(n, vi());
	rep(i, 0, m) {
		int x, y; cin >> x >> y;
		--x, --y;
		adj[x].emplace_back(y);
		adj[y].emplace_back(x);
	}
	queue<int> qu;
	qu.emplace(1);
	dist[1]=0;
	int lev = 1;
	vector<bool> vis(n, 0);
	vis[1]=1;
	while(sz(qu)) {
		int lim = sz(qu);
		rep(i, 0, lim) {
			int u = qu.front();
			qu.pop();
			for(auto& v: adj[u]) {
				if (not vis[v]) {
					vis[v]=1;
					dist[v] = lev;
					qu.emplace(v);
				}
			}
		}
			++lev;
	}
	dias = dist[0] / k + (dist[0]%k?1:0);
  int a;
  if (dist[0] == inf) {
    cout << 0<< '\n';
    return 0;
  }
	//dbg(dias);
	//for(auto x: dist){cout << x << ' ';} cout <<'\n';
	memo.assign(n+2, vector<vi>(dias+3, vi(k+3, -1)));
	cout << dp(0, 0, 0) <<'\n';
}
