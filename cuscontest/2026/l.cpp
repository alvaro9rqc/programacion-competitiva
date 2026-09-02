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

struct UF {
	vi e;
  int xd;
	UF(int n) : e(n, -1),  xd(n) {}
	bool sameSet(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
    --xd;
		e[a] += e[b]; e[b] = a;
		return true;
	}
};

ll mod = 1e9+7;
inline ll fe(ll b, ll e) {
  ll r = 1;
  while(e) {
    if(e&1) r=r*b%mod;
    e>>=1;
    b=b*b%mod;
  }
  return r;
}

void solve() {
  int n, m, k;cin>>n>>m>>k;
  vector<ii> edg(m);
  for(auto& [u,v]: edg) cin>>u>>v,--u,--v;
  //cn
  ll ans = 0;
  for (auto i = 0; i < (1<<m); i++) {
    UF uf(n);
    for (auto e = 0; e < m; e++) 
      if(1<<e&i) uf.join(edg[e].first,edg[e].second);
    ans=(ans + (__builtin_popcount(i)&1?-1:1) * fe(k,uf.xd)+mod)%mod;
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

