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
  const ll lim = 40;
  while(t--){
    ll n, k; cin >> n>>k;
    list<ll> left,right;
    ll exp = min(n-1,lim);
    if (k > (1ll<<exp)) {
      cout << -1 << '\n';
      continue;
    }
    for (ll i = 1; i <n ; ++i) {
      exp = min(n-i-1, lim);
      if (k > (1ll<<exp)) {
        right.push_front(i);
        k -= 1ll << exp;
      } else {
        left.push_back(i);
      }
    }
    left.push_back(n);
    for(auto& e: left) cout << e << ' ';
    for(auto& e: right) cout << e << ' ';
    cout << '\n';
  }
}


