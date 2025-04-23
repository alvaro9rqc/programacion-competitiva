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
    ll n, k; cin >> n >> k;
    vll a(n); 
    for(auto& e: a) cin >> e;
    sort(a.begin(), a.end());
    ll ans;
    for (ll i = 1; i < n; ++i) {
      ll nec = (a[i]-a[i-1])*i;
      if (nec > k){
        ll inc = k / i;
        ans = a[i-1]+inc;
        break;
      } else {
        ans= a[i];
        k -=nec;
      }
    }
    cout << ans << '\n';

  }
}


