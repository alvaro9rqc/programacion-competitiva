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

string a, b;
int na, nb;
vector<vi> memo;


int dp(int ai, int bi) {
  if (ai >= na) return nb-bi;
  if (bi >= nb) return na-ai;
  if (memo[ai][bi] != -1) return memo[ai][bi];
  //saltar
  int ans = 1 + dp(ai, bi+1);
  ans = min(ans, 1 + dp(ai+1, bi));
  //reemplazar o quedarse igual
  if (a[ai] == b[bi]) ans = min(ans, dp(ai+1, bi+1));
  else ans=min(ans, 1+dp(ai+1, bi+1));
  return memo[ai][bi] = ans;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  cin >> a >> b;
  na = sz(a);
  nb = sz(b);
  memo.assign(na, vi(nb, -1));
  cout << dp(0,0) << '\n';
}


