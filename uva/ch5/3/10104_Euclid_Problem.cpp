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
#define all(x) begin(x), end(x)

ll bezout(ll a, ll b, ll& x, ll& y) {
  ll xx = y = 0;
  ll yy = x = 1;
  while(b) {
    ll q = a / b;
    ll t = b; b = a % b; a = t;
    t = xx; xx = x-q*xx; x = t;
    t = yy; yy = y-q*yy; y = t;
  }
  return a;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  //cin.exceptions(cin.failbit);
  ll a, b;
  while(cin >> a >> b) {
    ll x, y; 
    ll g = bezout(a, b, x, y);
    printf("%lld %lld %lld\n", x, y, g);
    //ll i = (y - x) % (b + a);
    //ll k = (y - x) / (b + a);
    //if (i) {
    //  ll tx = x + k*b;
    //  ll ty = y - k*a;

    //  ll tx2 = x + (k+1)*b;
    //  ll ty2 = y - (k+1)*a;
    //  if (tx + ty < tx2 + tx2) printf("%lld %lld %lld\n", tx, ty, g);
    //  else printf("%lld %lld %lld\n", tx2, ty2, g);
    //} else {
    //  ll tx = x + k*b;
    //  ll ty = y - k*a;
    //  printf("%lld %lld %lld\n", tx, ty, g);
    //}
  }
}


