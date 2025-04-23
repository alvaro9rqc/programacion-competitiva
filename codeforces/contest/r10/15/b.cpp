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
    vll a(n);
    for(auto& e: a) cin >> e;
    sort(a.begin(), a.end());
    vll dbs;
    for (ll i = 1; i < n; ++i) {
      if (a[i] %a[0]==0 ) dbs.push_back(a[i]);
    }
    ll g = -1;
    if (dbs.size()>0u) g = dbs.back();
    for(auto& e: dbs) {
      g = gcd(g,e);
    }
    if (g == a[0]) cout << "yes\n";
    else cout << "no\n";
  }
}


