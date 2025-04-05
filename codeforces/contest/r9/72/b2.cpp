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
  ll t; cin >> t;
  while(t--){
    ll n, m , q;
    cin >> n >> m >> q;
    vll prf(m);
    for(auto& e: prf) cin >> e;
    sort(prf.begin(), prf.end());
    for (ll i = 0; i < q; ++i) {
      ll x; cin >> x;
      auto r = lower_bound(prf.begin(), prf.end(), x);
      if (r == prf.begin()) {
        cout << *r - 1 << '\n';
      } else if (r == prf.end()){
        cout << n - *(r-1) << '\n';
      } else {
        ll d = *r - *(r-1) - 1;
        if(d&1)++d;

        cout << d/2 << '\n';
      }
    }

  }
}


