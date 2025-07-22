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

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt; cin >> tt;
  while(tt--)  {
    ll a,b ,k; cin >> a >> b >> k;
    if (a == 0 and b == 0) {
      cout << 0<<'\n';
    }  else if (a == 0 or b == 0) {
      cout << 1<<'\n';
    } else {
      auto g = gcd(a,b);
      a /= g;
      b /= g;
      if (k >= a and k >= b) cout << 1<<'\n';
      else cout << 2 <<'\n';
    }
  }
}


