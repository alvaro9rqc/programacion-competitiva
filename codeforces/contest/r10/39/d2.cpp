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

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt; cin >> tt;
  while(tt--) {
    int n; cin >> n;
    vl a(n);
    for(auto& e: a) cin >> e;
    ll ans = 0;
    ll s2 = 1;
    ll s1 = a[n-2] < a[n-1] ? 1:2; ++s1;
    ans += s1+s2;
    for (auto i = n-3; i >= 0; --i) {
      ll x = 0;
      if (a[i] < a[i+1]) x = s1 +1;
      else x = s1 + n - i;
      ans+=x;
      s1= x;
    }
    cout << ans << '\n';
  }
}


