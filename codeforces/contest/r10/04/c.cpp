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

ll delta(ll n) {
  ll r = n % 10;
  if (r == 7) return 0;
  ll e = (r > 7)? r-7:10+r-3;
  n/=10;
  ll de = 10;
  ll idx = 1;
  while(n){
    r = n % 10;
    if (r==7) return 0; 
    if (r < 7) {
      if ( e >= 7 - r ) {
        de = ll(pow(10ll, idx));
        e = 7 - r;
      }
    } else {
      if (e > r - 7) {
        de = ll(pow(10ll, idx+1));
        e = r - 7;
      }
    }
    idx++;
    n /= 10;
  }
  return de;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t; cin >> t;
  while(t--){
    ll n; cin >> n;
    ll d = delta(n);
    for (auto i = 0; i < 10; ++i) {
      ll r = delta(n + d*i - i);
      cerr << n + d*i - i<<'\n';
      if (r == 0) {
        cout << i << '\n';
        break;
      }
    }
  }
}


