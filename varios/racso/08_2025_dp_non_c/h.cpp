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

int n, m;
vector<vl> memo;
vector<vl> gr;
ll inf = ll(1e14);

ll dp(int r, int c) {
  if (r == n-1 and c == m-1) return gr[r][c];
  if (r>= n or c >= m) return -inf;
  if (memo[r][c] != -1) return memo[r][c];
  ll ans = gr[r][c] + max(dp(r+1,c), dp(r,c+1));
  return memo[r][c] = ans;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  cin >> n >> m;
  memo.assign(n, vl(m, -1));
  gr.assign(n, vl(m));
  for(auto& r: gr) 
    for(auto& c: r) cin >> c;
  cout << dp(0,0)<<'\n';
}


