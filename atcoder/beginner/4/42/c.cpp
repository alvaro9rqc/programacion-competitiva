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
  int n, m; cin >> n >> m;
  vector<vi> adj(n);
  for (auto _ = 0; _ < m; _++) {
    int a,b; cin >> a >> b;
    --a,--b;
    adj[a].emplace_back(b);
    adj[b].emplace_back(a);
  }
  for (auto i = 0; i < n; i++) {
    ll ans = n - sz(adj[i])-1;
    ans=(ans)*(ans-1)*(ans-2)/6;
    cout << ans <<'\n';
  }
}

