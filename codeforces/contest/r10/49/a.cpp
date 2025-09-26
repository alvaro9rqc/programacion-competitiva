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
    string str; cin >> str;
    int ans = 0;
    int l = 0; int r = n-1;
    int m = 0;
    while(1) {
      for (auto i = l; i < n; i++) {
          l = i;
        if (str[i] == '1') {
          break;
        }
      }
      for (auto i = r; i >= 0; i--) {
          r = i;
        if (str[i] == '0') {
          break;
        }
      }
      if (r<= l) break;
      for (auto i = max(l+1,m); i < r; i++) {
        if (str[i] == '1') {
          m = i; 
          break;
        }
      }
      int xd1 = l, xd2 = r;
      if (m < l) swap(l,m);
      auto xd = str[r];
      str[r] = str[m];
      str[m] = str[l];
      str[l] = xd;
      ++ans;
      l=xd1, r=xd2;
    }
    cout << ans <<'\n';
  }
}


