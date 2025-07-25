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
#define sz(x) (ll)(x).size()
#define all(x) begin(x), end(x)

vector<vi> memo;
vector<vi> ans;
string s;
ll n; 

int dp(ll b, ll e) {
  if(b > e) return 0;
  if (memo[b][e] != -1) return memo[b][e];
  if (s[b] == s[e] and (e-b > 2?dp(b+1, e-1):1)) return memo[b][e] = 1;
  else return memo[b][e] = 0;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  cin >> s;
  n = sz(s);
  memo.assign(n, vi(n, -1));
  ans.assign(n, vi(n, 0));
  for (ll r = 0; r < n; ++r) {
    for (ll c = 0; c < n; ++c) {
      ans[r][c] = dp(r,c);
      if (r) ans[r][c] += ans[r-1][c];
      if (c) ans[r][c] += ans[r][c-1];
      if (r and c) ans[r][c] -= ans[r-1][c-1];
    }
  }
  int tt; cin >> tt;
  auto sum = [](int bl, int bu, int el, int eu) {
    ll r = ans[bu][eu];
    if (bl) r -= ans[bl-1][eu];
    if (el) r -= ans[bu][el-1];
    if (bl and el) r+=ans[bl-1][el-1];
    return r;
  };
  while(tt--) {
    int x, y; cin >> x >> y;
    --x,--y;
    cout << sum(x, y, x, y) <<'\n';
  }
  //for(auto& r: memo) 
  //  for(auto& c: r) cout << c<< (&c == &r.back()?'\n':' ');
    
  
}


