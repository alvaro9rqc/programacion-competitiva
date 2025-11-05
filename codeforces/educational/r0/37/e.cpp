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


set<int> nv;
vi scc;
set<ii> edg;

int dfs(set<int>::iterator x) {
  int vx = *x;
  nv.erase(x);
  int ans = 1;
  auto it = nv.begin();
  int na = 0;
  while(it!=nv.end()) {
    auto y = *it;
    if (edg.count({min(vx,y),max(vx,y)})) {
      na = y;
    } else {
      ans+=dfs(it);
    }
    it = nv.upper_bound(na);
  }
  return ans;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n, m; cin >> n >> m;
  for (auto i = 0; i < m; i++) {
    int x, y; cin >> x>>y;
    --x,--y;
    if (x > y) swap(x,y);
    edg.emplace(x,y);
  }
  for (auto i = 0; i < n; i++) nv.emplace(i);
  while(sz(nv)) {
    scc.emplace_back(dfs(nv.begin()));
  }
  sort(all(scc));
  cout << sz(scc)<<'\n';
  for(auto& i: scc) cout << i <<' ';
  cout <<'\n';
}

