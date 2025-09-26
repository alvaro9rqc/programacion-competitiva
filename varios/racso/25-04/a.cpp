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
  int tt; cin >> tt;
  while(tt--){
    ll a,b,c;
    cin >> a >> b >> c;
    bool can = false;
    ll x,y,z;
    for (x = 1; x*x <=c; ++x) {
      for (y = x; x*y <= b; ++y) {
        z = a - x - y;
        //cout << x << ' ' << y << ' ' << z << '\n';
        if (b == x*y*z and x*x + y*y + z*z == c) {
          can = true;
          break;
        }
        if (x*y*z > b) break;
      }
      if (can) break;
    }
    if (can)
      cout << x << ' ' << y << ' ' << z << '\n';
    else cout << "No solution.\n";
  }
}
