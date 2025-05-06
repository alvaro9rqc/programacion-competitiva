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
  int tc; cin >> tc;
  while(tc--){
    ll aux = 0b010101010101010101010101010101;
    cout << aux << endl;
    ll r1; cin >> r1;
    cout << 0 << endl;
    ll r2; cin >> r2;
    cout << '!' << endl;
    ll m; cin >> m;
    ll dif = r1 - r2;
    ll x,y; x = y=0;
    for (int i = 0; i < 30; i+=2) {
      if ( dif & (1ll<<i) ) x|=(1ll<<i);
      else {
        if (not ( dif & (1ll<<(i+1)) )) x|=(1ll<<i), y|=(1ll<<i);
      }
    }
    ll df2 = r2 - (x+y);
    for (int i = 1; i < 30; i+=2) {
      if (df2 & (1ll << i)) x |= (1ll<<i);
      else {
        if(df2 & (1ll << (i+1))) x|=(1ll<<i), y|= (1ll<<i);
      }
    }
    cout << ( m | x ) + ( m | y ) << endl;
  }
}


