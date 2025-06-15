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

ll f(ll k, ll m, ll d) {
  if (k < m) return 0;
  ll a = (k - m) / d;
  if ((k-a*d) >= m) ++a;
  return a;
} 

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll k, a, b, x, y;
  ll tt; cin >> tt;
  while(tt--) {
    cin >> k>>a >> b >> x >> y;
    if (y < x) {
      swap(a,b);
      swap(x,y);
    }
    ll ans = f(k, a, x);
    k -= ans*x;
    ans += f(k, b,y);
    cout << ans << '\n';

  }
}


