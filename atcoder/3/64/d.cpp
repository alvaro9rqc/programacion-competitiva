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

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll N, Q; cin >> N>>Q;
  vll A(N); 
  for(auto& e: A) cin >> e;
  sort(A.begin(), A.end());
  auto d = [&A] (ll i, ll x) {
    return abs(A[i] - x);
  };
  for (auto i = 0; i < Q; ++i) {
    ll b, k; cin >> b >> k;
    ll l=0, r= k-1;
    ll p = lower_bound(A.begin(), A.end(), b) - A.begin();
    if(p == N) --p;
    if (p != 0) {
      if ( abs(b - A[p]) > abs(b - A[p-1]) )
        --p;
    }
    if (k == 1) {
      cout << d(p,b)<<'\n';
      continue;
    }
    while(true) {
      //cout << l <<' ' << r <<"\n";
      if (l < 0 or r >= N) {
        break;
      }
      if(d(l,b) > d(r,b)) {
        if ( r == N-1 or  d(r+1,b) >= d(l,b)) {
          cout << d(l,b) <<'\n';
          break;
        } else {
          ll dt = ( p - l )/2;
          if (dt == 0) dt= 1;
          l += dt;
          r+=dt;
          if (r >= N) {
            l -= r -N+1;
            r = N-1;
          }
        }
      } else {
        if( l == 0 or d(l-1, b) >= d(r,b) ) {
          cout << d(r,b) <<'\n';
          break;
        } else {
          ll dt = (r - p) / 2;
          if (dt == 0) dt++;
          l -= dt;
          r -= dt;
        }
      }
    }
  }

}


