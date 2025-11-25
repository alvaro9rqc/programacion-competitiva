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

vector<vector<ii>> adj;
vi p;
vector<vi> memo;
int r,zp; 
vector<bool> vis;
int inf = int(1e8);

bool dfs(int x, int des) {
  vis[x]=1;
  if (x == des) return 1;
  for(auto& [y,w]: adj[x]) {
    if (not vis[y]) {
      p.emplace_back(w);
      if (dfs(y,des)) return 1;
      p.pop_back();
    }
  }
  return 0;
}


int dp(int i, int c) {
  if (i == zp-1) return (c+p[i] ==r)?1:inf;
  if (c > r) return inf;
  if (memo[i][c]!=-1) return memo[i][c];
  return memo[i][c] = min(
    1+dp(i+1, c+p[i]),
    2+dp(i,c+p[i]*2)
  );
}


int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt; cin >> tt;
  while(tt--) {
    int m;
    int n;cin >> n>>m;
    adj.assign(n, vector<ii>());
    for (auto i = 0; i < m; i++) {
      int x, y, w; cin >> x >> y >> w;
      --x,--y;
      adj[x].emplace_back(y, w);
      adj[y].emplace_back(x, w);
    }
    int k; cin >>k;
    for (auto i = 0; i < k; i++) {
      int x, y;cin >> x>>y >> r;
      if (x == y) {cout <<"No\n"; continue;}
      --x; --y;
      vis.assign(n,0);
      p.clear();
      dfs(x,y);
      //for(auto& i: p) cout <<i<<'\n';
      zp = sz(p);
      memo.assign(zp, vi(r+1,-1));
      int ans = dp(0,0);
      if (ans >= inf) cout << "No";
      else cout << "Yes " << ans;
      cout <<'\n';
    }
    if (tt) cout <<'\n';
  }

}

