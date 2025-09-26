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

vi memo(5e3,-1);
int p[] = {0,0,0};

int dp(int n) {
  if (n < 0) return 0;
  if (memo[n] != -1) return memo[n];
  int ans = 0;
  for (auto i = 0; i < 3; ++i) {
    if (n == p[i]) ans = max(ans, 1);
    if (dp(n-p[i]) > 0) ans = max(ans, 1+dp(n-p[i]));
  }
  return memo[n] = ans;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n; cin >> n;
  cin >> p[0]>>p[1]>>p[2];
  cout << dp(n);
}


