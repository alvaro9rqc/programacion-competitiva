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

ll f(ll n) {
  ll ans = 0;
  //2
  ans += n / 2;
  //3
  ans += n / 3 - n / 6;
  //5
  ans += n / 5 - n / 10 - n / 15 + n / 30;
  //7
  ans += n / 7 - n / 14 - n / 21 - n / 35 + n / 42 + n / 70 + n / 105 - n / 210;
  return n - ans;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt; cin >> tt;
  while(tt--) {
    ll l, r; cin >> l >> r;
    cout << f(r) - f(l-1) <<'\n';
  }
}


