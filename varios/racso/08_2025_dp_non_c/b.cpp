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

int n;
ll a, b;
vector<vl> memo;
string s;
ll inf = ll(1e15);

ll dp(int i, int lev) {
  if (i == n) { 
    return lev == 1? b:inf;
  }
  if (memo[lev][i] != -1) return memo[lev][i];
  ll ans = inf;
  if (lev == 1) {
    if (s[i] == '0') ans = min( 
        dp(i+1, 2) + b + (a<<1), 
        dp(i+1, 1) + b + a
        );
    else ans = inf;
  } else {
    if (s[i] == '0')
      ans = min(
          dp(i+1, 1) + (b<<1) + (a<<1),
          dp(i+1, 2) + (b<<1) + a
          );
    else ans = dp(i+1, 2) + (b<<1) + a;
  }
  return memo[lev][i] = ans;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt; cin >> tt;
  while(tt--) {
    cin >> n >> a >> b;
    cin >> s;
    memo.assign(3, vl(n, -1));
    cout << dp(0, 1)<<'\n';
    //for(auto& e: memo[1]) cout << e << ' ';
    //cout << '\n';
    //for(auto& e: memo[2]) cout << e << ' ';
    //cout << '\n';
  }
}


