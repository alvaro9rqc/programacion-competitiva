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
    int r;
    for (auto i = 3; i <= min(n, 75); ++i) {
      cout << "? " << i-2 << " " << i-1 <<" " << i << endl;
      cin >> r;
      if (!r) {
        cout << "! " << i-2 <<" "<<i-1<<" "<<i<<endl;
      }
    }
    if (r) return 0;
  }
}


