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
    ll n,k; cin >> n >> k;
    vll r(n), l(n);
    for(auto& e: l) cin >> e;
    for(auto& e: r) cin >> e;
    ll ans = 0;
    vll tr;
    for (ll i = 0; i < n; ++i) 
    {
      ans += max(r[i], l[i]);
      tr.push_back(min(r[i], l[i]));
    }
    sort(tr.rbegin(), tr.rend());
    for (ll i = 0; i < k-1; ++i) ans += tr[i];
    cout << ans+1 << '\n';
  }
}


