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
#define all(x) begin(x), end(x)

int inf = 4e6;
int n, m;
vector<tuple<int,int,int>> edj;
vector<vi> memo;

int dp(int e, int mask) {
  if (not mask) return 0;
  if (e == m) return inf;
  if (memo[e][mask] !=-1) return memo[e][mask];
  int ans = dp(e+1, mask);
  auto [u, v, w] = edj[e];
  /*if (mask & ( 1<<u | 1<<v ))*/ ans = min(ans, w + dp( e+1,mask^(1<<u|1<<v) ));
  //cout << e << ' '<<(mask^(1<<u|1<<v)) << '\n';
  return memo[e][mask] = ans;
}



int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  cin >> n >> m;
  memo.assign(m, vi(1<<n, -1));
  ll sum = 0;
  int mask = 0;
  for (auto i = 0; i < m; ++i) {
    int x, y , w;
    cin >> x >> y >> w;
    sum+=w;
    edj.emplace_back(x,y,w);
    mask^= (1<<x)|(1<<y);
  }
  cout << sum + (dp(0, mask)) << '\n';
}


