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

ll f(ll n, ll m) {
  ll a; ll b;
  for (auto i = 60; i >= 0; --i) {
    if ((1ll<<i) & n) {
      a = i;
      if (n != (1ll<<a)) ++a;
      break;
    }
  }
  for (auto i = 60; i >= 0; --i) {
    if ((1ll<<i) & m) {
      b = i;
      if (m != (1ll<<i)) ++b;
      break;
    }
  }
  return  a+b;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt; cin >> tt;
  while(tt--) {
    ll n, m, a, b;
    cin >> n >> m >> a >> b;
    ll x = min(f(n, b), f(n, m-b+1));
    ll y = min(f(a, m), f(n-a+1, m));
    cout << 1+min(x,y)<<'\n';
  }
}


