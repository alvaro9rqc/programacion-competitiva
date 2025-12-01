#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
#define dbg(x) cerr << #x << " = " << (x) << endl;
#define raya cerr << " ==================== " << endl;
#define rep(i, a, b) for (auto i = a; i < (b); ++i)
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)

vl mm1, mm2,arr,brr;
int n;
ll inf = ll(1e17);

ll dp(int i) {
  if (i == n) return -inf;
  if (mm1[i]!= -inf) return mm1[i];
  return mm1[i] = max(arr[i], arr[i]+dp(i+1));
}

ll dp2(int i) {
  if (i == n) return -inf;
  if (mm2[i] != -inf) return mm2[i];
  ll ans = arr[i]+brr[i];
  ans= max(ans, ans+dp(i+1));
  return mm2[i] = max(ans, arr[i]+dp2(i+1));
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt; cin >> tt;
  while(tt--) {
    cin >> n;
    ll k; cin >> k;
    arr.assign(n, -inf);
    brr.assign(n, -inf);
    mm1.assign(n, -inf);
    mm2.assign(n, -inf);
    for(auto& i: arr) cin >> i;
    for(auto& i: brr) cin >> i;
    ll ans = -inf;
    for (auto i = 0; i < n; i++) {
      if (k&1) ans = max(ans, dp2(i));
      else ans = max(ans, dp(i));
    }
    cout << ans <<'\n';
  }
}


