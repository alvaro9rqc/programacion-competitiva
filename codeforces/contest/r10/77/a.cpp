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
  int tt;cin >> tt;
  while(tt--) {
    int n; cin >> n;
    vi ans = {1};
    int mi = 1;
    int ma = n+1;
    for (auto i = n-1; i >= 0; i--) {
      if ((n-i) % 2==0)
        ans.emplace_back(++mi);
      else 
        ans.emplace_back(--ma);
    }
    for (auto i = n-1; i >= 0; i--) {
      cout << ans[i]<<' ';
    }
    cout <<'\n';
  }
}

