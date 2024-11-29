#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int extEuclid(ll a, ll b, ll& x, ll& y) {
  ll xx=y=0;
  ll yy=x=1;
  while(b) {
    ll q = a/b;
    ll t = b; b = a%b; a = t;
    t = xx; xx= x - q*xx; x=t;
    t = yy; yy = y - q*yy; y = t;
  }
  return a;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t;
  cin >>t;
  while (t--) {
    ll x, k;
    cin >> x >> k;
    ll xkc, xkf;
    xkc = xkf = x /k;
    if(x % k != 0) xkc++;
    ll p, q, div;
    div = extEuclid(xkf, xkc, p, q);
    div = x / div;
    //cout << x <<' '<<k<<'\n';
    cout << div * p << ' ' << div* q << '\n';
  }
  return 0;
}


