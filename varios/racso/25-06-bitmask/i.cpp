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
  ll a, b;
  cin >> a >> b;
  ll ans = 0;
  for (int i = 62; i >= 0; --i) {
    if ( (1ll<<i&a)!=((1ll<<i&b)) ) {
      ans += (1ll<<++i) -1;
      break;
    }
  }
  cout << ans << '\n';
}


