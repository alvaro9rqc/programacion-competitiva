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
  ll T; cin >> T;
  while(T--) {
    ll n; cin >> n;
    ll N = 2*n;
    vll A(N);
    unordered_set<ll> s;
    for(auto& e: A) 
    {
      cin >> e;
      s.insert(e);
    }
    sort(A.rbegin(), A.rend());
    ll acs = 0;
    for (ll i = 1; i < N; i+=2) {
      acs+= A[i-1]-A[i];
    }
    ll x = acs;
    ll idx = 1;
    while( s.find(x) != s.end() and x > 0 ) {
      if (idx >= N) break;
      x += A[idx] - A[idx-1];
      idx += 2;
    }
    if (s.find(x) != s.end()) {
      x = acs;
      idx = 1;
      while(s.find(x) != s.end() and x > 0) {
        if (idx >= N) break;
        x += A[idx-1]-A[idx];
        idx +=2;
      }
    }
    cout << x <<' ';
    for(auto& e: A) cout << e <<' ';
    cout <<'\n';

  }
}


