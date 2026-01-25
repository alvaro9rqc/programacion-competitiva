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

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt; cin >> tt;
  while(tt--) {
    int n; cin >> n;
    vl arr(n); for(auto& i: arr) cin >> i;
    if (n<3) {
      cout << n-1<<'\n';
      continue;
    }
    int ans = 0;
    ll ma=arr[1]-arr[0];
    ll mi = 0;
    for (auto i = 1; i < n-1; i++) {
      ll nd = arr[i+1]-arr[i];
      ll pd = arr[i]-arr[i-1];
      ll nmi = pd - ma;
      ll nma = pd - mi;
      nma = min(nma, nd);
      if (nmi>= nd) {
        mi=0, ma=nd;
      } else mi=nmi, ma=nma, ++ans;
    }

    cout << ans + 1<<'\n';
  }
}

