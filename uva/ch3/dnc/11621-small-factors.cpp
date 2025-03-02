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
  vll c;
  const ll N = 1ll << 32;
  for (ll i = 1; i < N; i*=2) {
    for (ll j = i; j < N; j*=3) {
      c.push_back(j);
    }
  }
  sort(c.begin(), c.end());
  ll m; 
  while(cin >> m) {
    if(m==0) break;
    cout << *(lower_bound(c.begin(), c.end(), m))<<'\n';
  }
}


