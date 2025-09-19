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

vl memo;
vector<vi> adj;
ll mod = ll(1e9+7);
int n, m; 

ll dp(int u) {
  if (u == n-1) return 1;
  if (memo[u]!=-1) return memo[u];
  ll ans = 0;
  for(auto& v: adj[u]) {
    ans+=dp(v);
    ans%=mod;
  }
  return memo[u]=ans;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  cin >> n >> m;
  adj.assign(n, vi());
  memo.assign(n,-1);
  for (auto i = 0; i < m; i++) {
    int a, b; cin >> a >> b;
    --a, --b;
    adj[a].emplace_back(b);
  }
  cout << dp(0)<<'\n';
}

