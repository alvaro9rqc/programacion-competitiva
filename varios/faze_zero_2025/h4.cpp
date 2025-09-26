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

  int l = (i+1)/2;
  int m = l;
  int r = ((i+1)&1) ? l:l-1;
  ll ans = 0;
  int f = -1;
  int one = -1;
  while (i >= l) {
    if ((n&(1ll<<l)) and (n&(1ll<<r))) {
      if (one == -1) one = l;
      ans |= 1ll<<l;
      ans |= 1ll<<r;
    } else if (n&(1ll<<l)) {
      //si a tiene un uno
      int t = l;
      f = l;
      if (one != -1) {
        t = one;
        ans = ~ ans;
        ans |= 1ll<<one;
        ans |= 1ll<<(i-one);
        ans = ~ ans;
        f = -1;
      }
      for (auto k = m; k < t; ++k) {
        ans |= 1ll<<k;
        ans |= 1ll<<(i-k);
      }
      for (auto k = t+1; k <= i; ++k) {
        if (n & (1ll<<k)) {
          ans |= 1ll<<k;
          ans |= 1ll<<(i-k);
        }
      }
      break;
    } else if (n&(1ll<<r)) {
      for (auto k = l; k <= i; ++k) {
        if (n & (1ll<<k)) {
          ans |= 1ll<<k;
          ans |= 1ll<<(i-k);
        }
      }
      break;
    }
    ++l,--r;
  }
  if (f != i) cout << ans << '\n';
  else {
    ans = 0;
    for (auto k = 0; k < i; ++k) {
      ans |= 1ll<<k;
    }
    cout << ans << '\n';
  }
}


