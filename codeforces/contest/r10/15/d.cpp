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
  ll t; cin>>t;
  while(t--){
    ll n,m,k; cin >> n >> m >> k;
    vll ans;
    ll lat = 0;
    while(true) {
      for (ll rep = 0; rep < m+1; ++rep) {
        ll p = lat;
        for (auto i = 0; i < k; ++i) {
          ans.push_back(p+i);
          if(ll( ans.size() ) == n )break;
        }
        if(ll( ans.size() ) == n )break;
      }
      lat +=k;
      if(ll( ans.size() ) == n )break;
    }
    for(auto& e: ans) {
      cout << e << ' ';
    }
    cout << '\n';
  }
}


