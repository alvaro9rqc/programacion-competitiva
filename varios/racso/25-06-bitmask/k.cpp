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

ll fx(ll n, ll i) {
  if (n < (1ll<<i)) return 0;
  return n - (1ll<<i)+1;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll a, b; cin >> a >> b;
  char f = 1;
  ll d = b -a;
  ll ans = 0;
  if (a == b) {
    cout << a << '\n';
    return 0;
  }
  for (int i = 43; i > 0; --i) {
    if (f and (1ll<<(i+1)&a) != (1<<(i+1)&b)) f=0;
    else if (not f) {
      ll m = (1ll<<(i+1));
      ll d2 = d % m;
      ll ones = -fx(a%m, i);
      if (a%m + d2 >= m) ones += fx(m-1, i) + fx((a%m+d2)%m, i);
      else ones += fx(a%m +d2, i);
      if (a&1ll<<i) ++ones;
      if (ones&1) ans|=1ll<<i;
    }
  }
  if (a&1 and (d/2+1)&1) ans |= 1; 
  if (not(a&1) and (d/2+(d&1))&1) ans |= 1;
  cout << ans << '\n';
}


