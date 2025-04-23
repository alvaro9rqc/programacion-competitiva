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
    while(t--) {
      ll n, k;
      cin >> n >> k;
      vll a(n);
      for(auto& e: a) cin >> e;
      vll pos;
      for (ll i = 0; i < n; ++i) {
        if (a[i] <= k) pos.push_back(i);
      }
      auto peq = [&](ll l, ll r, ll &pr, ll& pl) {
        ll it = ll( lower_bound(pos.begin(), pos.end(), l)-pos.begin() );
        for(auto i = it; i < ll(pos.size()) and pos[i] <= r; ++i){
          ll mid = pos[i] - l + 1;
          mid = mid / 2 + ( (mid&1)?1:0 );
          if (i+1 >= mid) {
            pr=l;
            pl =pos[i];
            return true;
          }
        }
        it = ll(upper_bound(pos.begin(), pos.end(), r) - pos.begin());
        --it;
        for (auto i = it; i >= 0 and pos[i]>=l; --i) {
          ll mid = r-pos[i] +1;
          mid = mid / 2 + ( (mid&1)?1:0 );
          if (ll(pos.size()) - i >= mid) {
            pl = pos[i];
            pr = r;
            return true;
          }
        }
        return false;
      };
      ll r,l;
      if (peq(0, n-1, l,r)) {
        ll nr, nl;
        if (l == 0) nl=r+1, nr=n-1;
        else nl=0, nr=l-1;
        if (peq(nl,nr,l,r)) cout << "yes\n";
        else cout << "no\n";
      } else cout << "no\n";

  }
}


