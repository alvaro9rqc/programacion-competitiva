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

ll inf = 1e18;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tt; cin >> tt;
  while(tt--) {
    ll n; cin >> n;
    vl v(n); 
    for(auto& e: v) cin >> e;
    vl R(n+3);
    vl L(n+3);
    ll ans = inf;
    for (auto i = n-1; i >= 0; --i) {
      R[v[i]]++;
    }
    ll l = 0;
    for (ll r = 0; r < n; ++r) {
      ll lans = 0;
      --R[v[r]];
      while (v[l] != v[r]) {
        ++L[v[l]];
        ++l;
      }
      if (L[v[r]] != l) lans += v[r] *l;
      if (R[v[r]] != (n-1-r)) lans += v[r] * (n-1-r);
      ans = min(ans, lans);
    }
    cout << ans << '\n';
  }
}


