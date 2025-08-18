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
int n;
vector<vi> memo(4);

int dp(int i, int p) {
  if (i == n) return 0;
  if (memo[p][i] != -1) return memo[p][i];
  int ans = 0;
  if (p < 3) {
    char c = p == 1?'a':'b';
    ans = (s[i] == c?1:0) + max(dp(i+1, p+1), dp(i+1, p));
    ans = max(ans, dp(i, p+1));
  } else {
    ans = (s[i] == 'a') + dp(i+1, p);
  }
  return memo[p][i] = ans;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  cin >> s;
  n = sz(s);
  memo[1].assign(n, -1);
  memo[2].assign(n, -1);
  memo[3].assign(n, -1);
  cout << dp(0, 1) << '\n';
}


