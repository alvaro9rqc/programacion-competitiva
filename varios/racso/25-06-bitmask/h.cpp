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
  int n; cin >> n;
  while(n--) {
    ll ans = 0;
    ll l, r; cin >> l >> r;
    for (int i = 62; i >= 0; --i) {
      if ( ((1ll<<i)&l) == ((1ll<<i)&r) ) ans |= (1ll<<i)&l;
      else {
        ll x = 1ll<<i;
        --x;
        //cerr<<"x: "<<x<<'\n';
        //cerr<<"a: "<<ans<<'\n';
        if (ans + (x<<1) + 1 == r) ans += (x<<1)+1;
        else ans += x;
        break;
      }
    }
    cout << ans << '\n';
  }
}


