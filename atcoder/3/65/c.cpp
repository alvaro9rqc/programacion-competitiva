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
  ll N,M;
  cin >> N >> M;
  vll A(N);
  ll acs =0;
  for(auto& e: A) {
    cin >> e;
    acs+=e;
  }
  auto f = [&M, &A](ll x) {
    ll b = M;
    for(auto& e: A) {
      b -= min(x, e);
      if (b < 0) return false;
    }
    return true;
  };
  if(acs <= M) 
    cout << "infinite\n";
  else {
    ll l=1,r=M;
    while(l<r) {
      ll m=(l+r+1)/2;
      if( f(m) ) {
        l=m;
      } else {
        r=m-1;
      }
    }
    cout << l <<'\n';
  }
}


