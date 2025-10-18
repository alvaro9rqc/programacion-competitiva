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

int n, m, tgt;
vector<vector<vi>> memo;
vector<vi> adj;
int inf = int(1e3);

int dp(int a, int b, int mask){
  if (memo[a][b][mask]!= -1) return memo[a][b][mask];
  if (a == tgt and b == tgt) return 0;
  int ans = inf;
  if (a != tgt) {
    for(auto& v: adj[a]) {
      if ((1<<v)&mask) {
        if (v != tgt) mask&= ~(1<<v);
        ans = min(ans, 1+dp(v, b, mask));
        if (v != tgt) mask|= (1<<v);
      }
    }
  }
  if (b != tgt) {
    for(auto& v: adj[b]) {
      if ((1<<v)&mask) {
        if (v != tgt) mask&= ~(1<<v);
        ans = min(ans, 1+dp(a, v, mask));
        if (v != tgt) mask|= (1<<v);
      }
    }
  }
  return memo[a][b][mask] = ans;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  cin >> n >> m;
  adj.assign(n, vi());
  memo.assign(n, vector<vi>(n, vi(1<<n,-1)));
  map<int,int> ma;
  for (auto i = 0; i < m; i++) {
    int a, b; cin >> a >> b;
    if (not ma.count(a)) ma[a]=sz(ma);
    if (not ma.count(b)) ma[b]=sz(ma);
    a=ma[a];
    b=ma[b];
    if (a == b) continue;
    adj[a].emplace_back(b);
    adj[b].emplace_back(a);
  }
  int a, b; cin >> a >> b;
  if (not ma.count(a)) ma[a]=sz(ma);
  if (not ma.count(b)) ma[b]=sz(ma);
  a=ma[a];
  b=ma[b];
  cin >> tgt;
  if (not ma.count(tgt)) ma[tgt]=sz(ma);
  tgt=ma[tgt];
  int mask = (1<<n)-1;
  if (a!=tgt)
    mask &= ~(1<<a);
  if (b!=tgt)
    mask &= ~(1<<b);
  int ans = dp(a,b, mask);
  if (a == b and a != tgt) ans = inf;
  if (ans == inf) cout << "Impossible\n";
  else cout << ans << '\n';
}

