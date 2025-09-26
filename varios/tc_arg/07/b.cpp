#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
#define dbg(x) cerr << #x << " = " << (x) << endl;
#define raya cerr << " ==================== " << endl;
#define FOR(i, a, b) for (auto i = a; i < (b); ++i)
#define sz(x) (int)(x).size()

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt; cin >> tt;
  while(tt--) {
    int n; cin >> n;
    bool fase=true;
    vi ans(n);
    int r;
    for (auto i = 2; i < n; ++i) {
      if (fase) {
        cout << "? " << i << " " << 1 <<endl;
        cin >> r;
        if (!r) {
          fase = false;
          ans[i] = 1;
        } 
      } else {
        int q = ans[i-1]+1;
        while(1) {
          cout << "? " << i<<" " << q <<endl;
          cin >> r;
          if (!r) {
            ans[i] = q;
            break;
          } else {
            ++q;
          }
        }
      }
    }
    cout << "! ";
    for (auto i = 1; i < n; ++i) {
      cout << ans[i] <<' ';
    }
    cout << endl;
  }
}


