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
  ll N; 
  while (cin >> N){
    if (N == 0) break;
    ll ax = 0;
    ll acs = 0;
    for (ll i = 0; i < N; ++i) {
      ll x; cin >> x;
      acs += x;
      if (acs < 0) acs = 0;
      ax = max(ax, acs);
    }
    if (ax)
      //cout << ax << '\n';
      printf("The maximum winning streak is %lld.\n",ax );
    else 
      printf("Losing streak.\n");
  }
  return 0;
}


