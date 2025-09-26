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
  int l = i, r = 0;
  if (n&1) {
    ll ans = 0;
    while(l >= r){
      if ( (n&(1ll<<l)) and (n&(1ll<<r))) {
        ans |= 1ll<<l;
        ans |= 1ll<<r;
      } else if ( (n&(1ll<<l))) {
        for (auto j = r+1; j < l; ++j) {
          ans |= 1ll<<j;
        }
        break;
      } 
      --l,++r;
    }
    cout << ans << '\n';
  } else {
    ll ans = 0;
    for (auto j = r; j < i; ++j) {
      ans |= 1ll<<j;
    }
    cout << ans;
  }
}


