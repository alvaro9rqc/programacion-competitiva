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
    ll n,k,x;
    cin >> n >> k >> x;
    ll sumS = 0;
    vll a(n);
    vll acs(n);
    for(auto& e: a) cin >> e;
    acs[0]=a[0];
    for (ll i = 1; i < n; ++i) {
      acs[i] = a[i]+acs[i-1];
    }
    sumS=acs.back();
    ll ans = 0;
    auto sseg = [&acs](ll i, ll j){
      if (i == 0) return acs[j];
      return acs[j]-acs[i-1];
    };
    for (ll i = 0; i < n; ++i) {
      ll xp=x;
      ll l = 0;
      if (xp <= sseg(i, n-1)) l = 1;
      else {
        l = 1;
        xp -= sseg(i, n-1);
        l += xp / sumS;
        if (xp % sumS != 0) l+=1;
      }
      ll lans = k - (l-1);
      if (lans <= 0)break;
      ans += lans;
    }
    cout << ans << '\n';
  }
}


