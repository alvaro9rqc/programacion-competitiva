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

ll mod = ll(1e9+7);
int n, k, d;
vl mv, mn;

ll dp(int n, bool val) {
  if (val) {
    if (n < d) return 0;
    if(mv[n] != -1) return mv[n];
    ll ans = 0;
    for (auto i = 1; i <= k; ++i) {
      if (i >= d) ans+=dp(n-i, 0);
      else ans+=dp(n-i, 1);
      ans%=mod;
    }
    return mv[n] = ans;
  } else {
    if ( n < 0 ) return 0;
    if (mn[n] != -1) return mn[n];
    if (n == 0) return 1;
    ll ans = 0;
    for (auto i = 1; i <= k; ++i) {
      ans+=dp(n-i, 0);
      ans%=mod;
    }
    return mn[n] = ans;
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  cin >> n >> k >> d;
  mv.assign(n+3, -1);
  mn.assign(n+3, -1);
  cout << dp(n, 1)<<'\n';
}


