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
  int t; cin >> t;
  while(t--){
    ll n, k; cin >> n >> k;
    vll a(n);
    ll maxc=0;
    ll total=0;
    for(auto& e: a) 
    {
      cin >> e;
      total+=e;
      if (e > maxc)maxc=e;
    }
    ll size = min(n, (total+k)/maxc);
    for (ll i = size; i > 0; --i) {
      if (total % i != 0){
        ll dks = total / i + 1;
        ll r = dks - total % dks;
        if (r <= k) {
          cout << i << '\n';
          break;
        }
      } else {
        cout << i << '\n'; break;
      }
    }
  }
}


