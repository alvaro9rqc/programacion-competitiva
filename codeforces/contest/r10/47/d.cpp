#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
#define raya cerr << " ==================== " << endl;
#define rep(i, a, b) for (auto i = a; i < (b); ++i)
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt; cin >> tt;
  while(tt--) {
    int n;  cin >> n;
    vi brr(n);
    for(auto& i: brr) cin >> i;
    vector<vi> pos(n+1);
    for (auto i = 0; i < n; i++) {
      pos[brr[i]].emplace_back(i);
    }
    bool can = 1;
    int num = 1;
    vi ans(n);
    for (auto i = 1; i < n+1; i++) {
      if ((sz(pos[i]) % i) == 0) {
        int rep = sz(pos[i]) / i;
        for (auto j = 0; j < rep; j++) {
          for (auto m = j*i; m < j*(i)+i; m++) {
            ans[pos[i][m]] = num;
          }
          ++num;
        }
      } else {
        can = 0; break;
      }
    }
    if (can) {
      for(auto& i: ans) cout << i << ' ';
    } else
      cout << -1;
    cout <<'\n';
  }
}


