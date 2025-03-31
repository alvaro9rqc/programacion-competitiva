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
    ll n; cin >> n;
    vll s;
    for (ll i = 0; i < n; ++i) {
      vll r(n);
      for(auto& e: r) cin >> e;
      for (ll j = n-1; j >= -1; --j) {
        if (j ==-1 or r[j] != 1) {
          s.push_back(n-j-1);
          break;
        }
      }
    }
    sort(s.begin(), s.end());
    ll ans = 0;
    for(auto& e: s) 
      if ( ans <= e )++ans;
    cout << ans << '\n';
  }
}


