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
  int test; cin >> test;
  while(test--) {
    int n, m; cin >> n >> m;
    vector<int>a(m);
    for(auto& e: a) cin >> e;
    sort(a.begin(), a.end());
    ll ans = 0;
    ll par = 0;
    for (auto i = 1; i <= n/2; ++i) {
      auto up = lower_bound(a.begin(),a.end(), n-i);
      ////cerr << *( a.end()-1 ) <<' ';
      //ll x = ll( a.end()-lower_bound(a.begin(),a.end(), n-i)  );
      ll x = ll(a.end()-up);
      ll y = ll(up- lower_bound(a.begin(),up, i) );
      //cerr << i<<' '<<x<<' '<<y<<'\n';
      par = ( x*(x-1) + x*y );
      ans += par;
    }
    cout <<2*ans-(( n&1 )==0 ? par:0) <<'\n';
  }
}


