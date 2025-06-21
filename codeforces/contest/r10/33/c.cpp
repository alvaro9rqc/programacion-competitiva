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
const ll INF = 1e18;
const int MOD = 1e9 + 7;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt; cin >> tt;
  while(tt--) {
    ll n, m; cin >> n >> m;
    if ( m > ( n * (n+1) / 2 ) or m < n ) {
      cout << -1 << '\n';
      continue;
    }
    vl a (n);
    for (auto i = n; i > 0; --i) a[n-i] = i;
    vl ans;
    ll taken = 0;
    vector<bool> t(n+2, false); 
    for (auto i = 0; i < n; ++i) {
      ll d = m - a[i];
      if (d > n - taken-1) {
        ++taken;
        ans.push_back(a[i]);
        t[a[i]] = true;
        m -= a[i];
      } else if (d < n - taken-1) {
        continue;
      } else {
        ans.push_back(a[i]);
        t[a[i]] = true;
        if (a[i] == 1) break;
        ans.push_back(1);
        t[1]=true;
        break;
      }
    }
    for(auto& e: a) 
      if (not t[e])  ans.push_back(e);
    cout << ans[0]<<'\n';
    for (auto i = 1; i < n; ++i) {
      cout << ans[i-1] << ' ' << ans[i] << '\n';
    }
  }
}


