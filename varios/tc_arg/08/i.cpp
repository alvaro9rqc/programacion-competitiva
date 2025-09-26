#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
#define endl '\n'
#define dbg(x) cerr << #x << " = " << (x) << endl;
#define raya cerr << " ==================== " << endl;
#define FOR(i, a, b) for (auto i = a; i < (b); ++i)
#define sz(x) (int)(x).size()

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  ll n; cin >> n;
  vector<vl> g(n,vl());
  for (auto i = 0; i < n-1; ++i) {
    int x, y; cin >> x >> y;
    --x,--y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  vl tras(n);
  for(auto& e: tras) cin >> e, --e;
  queue<set<ll>> level;
  level.push({0});
  vector<bool> vis(n, false);
  vis[0] = 1;
  bool can = 1;
  auto it = tras.begin();
  while(not level.empty()) {
    auto v = *(it++);
    if (!level.front().count(v)) {can=0;break;}
    else level.front().erase(v);
    if (!level.front().size()) level.pop();
    set<ll> xd;
    for(auto& u: g[v]) {
      if (not vis[u]) {
        vis[u] = 1;
        xd.insert(u);
      }
    }
    if (xd.size()) level.push(xd);
  }
  cout << (can?"Yes":"No") <<'\n';
}


