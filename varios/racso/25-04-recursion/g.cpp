#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;

typedef pair<ll, ll> ll_p; 
typedef tuple<ll, ll, ll> ll_t; 
typedef vector<ll> vl;
typedef vector<ll_p> vll;   
typedef vector<ll_t> vlll;

ll si(ll n) {
  if (n < 4) return 3;
  else return (si(n/2) <<1) + 1;
}

ll f (ll t, ll n, ll l, ll r) {
  ll ans = 0;
  if (t == 3) {
    if (l == r) {
      return( l == 2 ? (n&1):1 );
    }
    for (ll i = l; i <= r; ++i) {
      ans += f(t,n,i,i);
    }
    return ans;
  }
  ll m = (t>>1) + 1;
  if (r < m) return f( (t>>1), n/2, l, r );
  else if (m < l) return f( (t>>1), n/2, l-m, r-m );
  else {
    if (l != m)
      ans += f(t>>1, n>>1, l, m-1);
    ans +=(n&1);
    if (r != m) 
      ans += f(t>>1, n>>1, 1, r-m);
  }
  return ans;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, l, r;
  cin >> n >> l >> r;
  ll t = si(n);
  cerr << t << '\n';
  if (n == 0) 
  {
    cout << 0 << '\n';
    return 0;
  }
  ll ans = f(t, n, l, r);
  cout << ans << '\n';
}


