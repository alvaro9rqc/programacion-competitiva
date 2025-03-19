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
typedef vector<ll> vll;
typedef vector<ll_p> vll_p;   
typedef vector<ll_t> vll_t;

vector<vll> memo(120,vll(70,-1));

vi sum(71,0);

void l_s() {
  for (auto i = 1u; i < sum.size(); ++i) {
    sum[i] = sum[i-1]+i;
  }
}

ll dp(int d, int b) {
  if (d <= 0) return 0;
  if (b == 1) return 2;
  if (memo[d][b] != -1) return memo[d][b];
  ll ans = (1ll<<b) + dp( d-b, b-1 );
  if (not (d > sum[b-1])) ans = min(ans, dp(d, b-1));
  return memo[d][b]=ans;
}


int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll T; cin >> T;
  l_s();
  while(T--) {
    ll x,y;
    cin >> x >> y;
    if (x == y) {
      cout << 0 <<'\n';
      continue;
    }
    if (x < y) swap(x,y);
    int d1=-1,d2=-1;
    for (auto i = 60; i >= 0; --i) 
      if ( (1ll << i) & x ) {
        d1 = i;
        break;
      }
    for (auto i = 60; i >= 0; --i) 
      if ( (1ll << i) & y ) {
        d2 = i;
        break;
      }
    if (d1 == -1 or d2 == -1) {
      //cout << d1<<' '<<d2<<'\n';
      cout << dp(d1+d2+2, d1+d2+2)<<'\n';
      continue;
    }
    int d = d1-d2;
    x >>= d;
    for(int i = d2; i >= 0;--i) 
      if ( (x&(1ll << i)) != (y&(1ll << i)) ) {
        d += 2*( i+1 );
        break;
      }
    //cout << d <<'\n';
    if (d == 2 and d1-d2 == 0) {
      cout << 12 <<'\n';
      continue;
    }
    cout << dp(d, 62)<<'\n';
  }
}


