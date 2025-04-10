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
typedef vector<ll> vll;
typedef vector<ll_p> vll_p;   
typedef vector<ll_t> vll_t;

bool f(ll& k, ll x, ll y){
  for (ll i = 0; i < 35; ++i) {
    if ( (x&(1ll<<i)) & (y&(1ll<<i)) ) {
      bool c = false;
      ll p = 0;
      for (ll j = i-1; j < 35; ++j) {
        if ( not( (x&(1ll<<j)) & (y&(1ll<<j)) )) {
          c=true;
          p |= (1ll<<i);
          break;
        }
      }
      if (not c) return false;
      x += p;
      y += p;
      k |= p;
    }
  }
  return true;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t; cin >> t;
  while(t--){
    ll x, y; cin >> x >> y;
    ll k=0;
    if ( f (k, x, y) ) cout << k <<'\n';
    else cout << -1 << '\n';
  }
}


