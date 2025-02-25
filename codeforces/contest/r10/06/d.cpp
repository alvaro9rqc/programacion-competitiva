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
  while(t--) {
    ll n; cin >> n;
    vll a(n);
    for(auto& e: a) cin >> e;
    ll r=0,l=0;
    ll c = 0;
    for (ll i = 0; i < n; ++i) {
      ll few=0, gret=0;
      for (ll j = i+1; j < n; ++j) {
        if(a[i] < a[j]) gret++;
        else if(a[i] > a[j]) few++;
        if (few - gret > c) {
          c = few - gret;
          r = i; 
          l = j;
        }
      }
    }
    cout << r+1 << ' ' <<l+1 <<'\n';
  }
}


