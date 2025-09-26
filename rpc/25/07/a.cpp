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

int n, b; 
vector<vi> memo;

int dp(int a, int x, int l, int r) {
  if (a and memo[l][r] != -1) return memo[l][r];
  if (not a and l == r) return l;
  if (a) {
    int ans = 1<<30;
    for (auto i = l; i <= r; ++i) {
      ans = min(ans, dp(0, i, l, r));
    }
    return memo[l][r] = ans;
  } else {
    if (x == l) return memo[l][r] = b + dp(1, 0, l+1, r);
    else if (x == r) return memo[l][r] = x + dp(1, 0, l, r-1);
    else return memo[l][r] = max(
        b + dp(1, 0, x+1, r),
        x + dp(1, 0, l, x-1)
        );
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  cin >> n >> b;
  memo.assign(n+1, vi(n+1, -1));
  ll ans = 1<<8;
  ans = dp(1, 0,  1, n);
  cout << ans << '\n';
}


