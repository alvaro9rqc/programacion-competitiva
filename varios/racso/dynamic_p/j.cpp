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

int n, m;
vi c;
vi memo;

int inf = 1e5;


int f(int d) {
  if (d == 0) return 0;
  if ( memo[d] != -1 ) return memo[d];
  int ans = inf;
  for (auto i = 0; i < m; ++i) {
    if (d-c[i] < 0) continue;
    ans = min(ans, 1+f(d-c[i]));
  }
  return memo[d] = ans;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  cin >> n >> m;
  c.resize(m);
  memo.assign(n+2, -1);
  for(auto& e: c) cin >> e;
  cout << f(n) <<'\n';
  
}


