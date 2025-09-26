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

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n; cin >> n;
  int i = 0;
  for (i = 60; i >= 0 ; --i) {
    if (n & (1ll<<i)) break;
  }
  ll ans = 0;
  int l = i, r = 0;
  // 100 impar
  // 101
  // 000
  // 010 -> 2
  // x ... x
  // 1 000 1
  // 0 111 0
  while(l >= r) {
    if ( (n&(1ll<<l)) and (n&(1ll<<r)==0)) {
      for (auto i = r+1; i < l; ++i) {
        ans |= 1ll<<i;
      }
    } else if ( (n&(1ll<<l)) and (n&(1ll<<r))) {
      ans |= 1ll<<l;
      ans |= 1ll<<r;
    } else if (  (n&(1ll<<l)==0) and (n&(1ll<<r)) )
    //activar
    // si cuando lo activo, es mayor que el original
    // lo desactivamos
    if (ans > n) {
      ans = ~ ans;
      ans |= 1ll<<l;
      ans |= 1ll<<r;
      ans = ~ ans;
    }
    --l, ++r;
  }
  cout << ans << '\n';
}


