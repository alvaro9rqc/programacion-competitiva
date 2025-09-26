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

string s;
vector<vi> adj;
int k;
vector<bool> vis;

int dfs(int u) {
  vis[u] = 1;
  if (sz(adj[u]) == 0) {
    k+=s[u-1] == '1';
    return s[u-1] == '1';
  }
  int sig = 0;
  for(auto& v: adj[u]) sig += dfs(v);
  // 1: 0,+1,1 - 1,0,1 - 2,0,1
  // 0: 0,0,0 - 1,1,1 - 2,0,0
  if (s[u-1] == '1') {
    k+= sig==0;
    return 1;
  } else {
    k+= sig == 1;
    return 0;
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt; cin >> tt;
  while(tt--) {
    int n; cin >> n;
    adj.assign(n+1, vi());
    vis.assign(n+1,0);
    k = 0;
    for (auto i = 1; i <= n; ++i) {
      int p = i + (i&-i);
      if (p <=n) adj[p].emplace_back(i);
    }
    //for (auto i = 1; i <= n; ++i) {
    //  cout  << ": "<<i<<':';
    //  for(auto& e: adj[i]) cout << e << ' ';
    //  cout  << '\n';
    //}
    cin >> s;
    for (auto i = n; i > 0; --i) {
      if (not vis[i]) dfs(i);
    }
    cout << k << '\n';
  }
}


