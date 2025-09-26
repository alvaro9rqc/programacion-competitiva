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

ll rate, n, m;

ll fpow(ll b, ll e) {
  ll a = 1;
  b %= m;
  if (b == 0) return 0;
  while(e){
    if (e&1) a = (a*b)%m;
    e>>=1;
    b = (b*b)%m;
  }
  return a;
}

ll f(ll l, ll r) {
  if ( l == r ) return fpow(rate, l);
  ll ans = 0;
  if ( (r-l+1)&1 ) {
    ans = f(r,r);
    --r;
  }
  ll d = r - l +1;
  d /= 2;
  ll temp = f(l, l+d-1);
  ans += temp;
  ans %= m;
  ans += (temp*(fpow(rate, l+d)%m))%m;
  ans %=m;
  //cerr << ans << " " << l <<" " << r<<'\n';
  return ans;
}


int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tt; cin >> tt;
  while(tt--) {
    cin >> rate >> n >> m;
    cout << f(0, n*n-1) << '\n';
  }
}


