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

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt; cin >> tt;
  while(tt--) {
    int n; cin >> n;
    vl a(n);
    ll ans = 0;
    for(auto& ei: a) cin >> ei;
    for(int i = 1; i < n; i+=2) {
      if (i+1 < n) {
        ll xd = 0;
        if (a[i-1] > a[i]) a[i-1]-=(xd=a[i-1]-a[i]);
        ans+=xd;
        xd=0;
        if (a[i+1] > a[i]) a[i+1]-=(xd=a[i+1]-a[i]);
        ans+=xd;
        xd=0;
        if (a[i-1]+a[i+1] > a[i]) a[i+1]-=(xd=(a[i-1]+a[i+1]-a[i]));
        ans+=xd;
        xd=0;
      } else {
        if (a[i-1] > a[i]) ans+=a[i-1]-a[i];
      }
    }
    cout << ans <<'\n';
  }
}


