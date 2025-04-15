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
    ll n; cin >> n;
    vll a(n);
    for(auto& e: a) cin >> e;
    ll ans = 0;
    vll pos(n, -1);
    ll rep = 0;
    for (auto i = 0ll; i < n; ++i) {
      if ( pos[ a[i]-1 ] == -1) pos[ a[i]-1 ] = i;
      else rep = max(rep, a[i]);
      ans += a[i];
      a[i] = rep;
    }
    rep = 0;
    //todos los pares
    vector<pair<ll,ll>> par;
    for (ll i = 1; i < n; ++i) {
      if (a[i] != a[i-1]) {
        par.emplace_back(rep, i-1);
        rep = i;
      }
    }
    par.emplace_back(rep, n-1);
    vector<pair<ll,ll>> val = {{0,0}};
    for(auto& [l, r]: par) {
      if (r - l > 0) val.emplace_back(l,r);
      else 
      {
        //ans += (val.back().second - val.back().first++ + 1) * a[l-1];
        if (r == n-1 and n > 1) {
          ans += ( val.back().second - val.back().first + 1 ) * a[l-1];
          val.back().first++;
        }
        val.back().second = r, ans += a[l];
      }
    }
    for(auto& [l, r]: val) {
      ans += (n - r -1) * (r - l + 1) * a[l];
      ans += (r - l + 1) * (r - l + 2) / 2 * a[l];
    }
    cout << ans << '\n';
  }
}


