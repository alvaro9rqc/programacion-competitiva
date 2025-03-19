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
  int T; cin >> T;
  while(T--) {
    ll n, k; cin >> n >> k;
    vector<pair<ll,ll>> A(n);
    ll ml, mr;
    for (ll i = 0; i < n; ++i) {
      ll a; cin >> a;
      A[i] = {a,i};
    }
    ml = A[0].first;
    mr = A.back().first;
    sort(A.rbegin(), A.rend());
    //for(auto& [v,i]: A) {
    //  cout << v <<' ' <<i<<'\n';
    //}
    ll l=n,r=0;
    ll ans = 0;
    if (k == 1) {
      auto [fe, fi] = A[0];
      if (fi == 0 or fi == n-1) {
        cout << fe + A[1].first<<'\n';
      } else {
        cout << fe + max(ml,mr)<<'\n';
      }
      continue;
    }
    for (ll i = 0; i <= k; ++i) {
      auto [e, idx] = A[i];
      ans += e;
      if (idx-1 < l) l = idx-1;
      if (idx+1 > r) r = idx+1;
    }
    cout << ans <<'\n';
    //for (ll i = k; i < n; ++i) {
    //  auto [e,idx] = A[i];
    //  if (idx == 0 or idx == n-1) {
    //    ans += e;
    //    break;
    //  }
    //  if (not( idx <= l or r <=idx  )) {
    //    ans += e;
    //    break;
    //  }
    //}
    //cout << ans <<'\n';
  }
}


