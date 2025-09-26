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
  int j = (i+1)/2;
  int k = ((i+1)&1) ? j:j-1;
  ll ans = 0;
  int one = -1;
  int m = j;
  for ( ; j <= i; ++j, --k) {
    if ((n&(1ll<<j)) and (n&(1ll<<k))) {
      if (one == -1)
        one = j;
      ans |= 1ll<<j;
      ans |= 1ll<<k;
    }else if ( (n&(1ll<<j)) ) {
      if (one != -1) {
        ans = ~ ans;
        ans |= 1ll<<one;
        ans |= 1ll<<(i-one);
        ans = ~ans;
        for (auto xd = m; xd < one; ++xd) {
          ans |= 1ll<<xd;
          ans |= 1ll<<(i-xd);
        }
        break;
      } {
        for (auto xd = m; xd < j; ++xd) {
          ans |= 1ll<<xd;
          ans |= 1ll<<(i-xd);
        }
        ++j, --k;
        break;
      } 
    } else if( n & (1ll<<k) ) {
      ++j,--k;
      break;
    }
  }
  for ( ; j <= i; ++j, --k) {
    //cout << "gaa\n";
    if (n&(1ll<<j)) {
      ans |= 1ll<<j;
      ans |= 1ll<<k;
    }
  }
  cout << ans << '\n';
}


