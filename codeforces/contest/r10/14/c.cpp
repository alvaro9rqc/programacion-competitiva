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
    ll n; cin >> n;
    vll even, odd;
    ll modd=0;
    for (ll i = 0; i < n; ++i) {
      ll x; cin >> x;
      if (x > modd) modd = x;
      if (x & 1) odd.push_back(x);
      else even.push_back(x);
    }
    if(even.size()==0 or odd.size()==0) cout << modd << '\n';
    else {
      ll ans = accumulate(even.begin(),even.end(), 0ll);
      ans += accumulate(odd.begin(),odd.end(), 0ll);
      ans -= odd.size()-1u;
      cout << ans << '\n';
    }
  }
}


