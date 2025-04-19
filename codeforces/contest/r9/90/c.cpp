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
  int t; cin >> t;
  while(t--){
    int n; cin >> n;
    int a = int( -1e5 +5);
    vii v(n);
    for(auto& [x,y]: v) cin >> x;
    for(auto& [x,y]: v) cin >> y;
    ll ans = 0;
    for(auto& [x,y]: v) {
      //cout << x <<' '<<y<<'\n';
      ans += max(x,y);
      if (min(x,y) > a) a = min(x,y);
    }
    cout << ans + a << '\n';
  }
}


