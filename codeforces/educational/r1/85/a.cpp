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
  while( tt-- ) {
    int n; cin >> n;
    int ans = 0;
    if (n == 1) ans = 1;
    else if (n == 2) ans = 9;
    else{
      ans = n*n*4 - n - 4;
      ans = max(ans, 5*(n*n-1-n));
    } 

    cout << ans <<'\n';
  }
}

