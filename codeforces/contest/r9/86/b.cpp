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
    ll n, b,c;
    cin >> n >> b >> c;
    if (b == 0) {
      if (c < n-2ll) cout << -1 << '\n';
      else {
        if (c < n) cout << n-1<<'\n';
        else cout << n<<'\n';
      }
    } else {
      ll l = n - c;
      if (l <= 0) { 
        cout << n << '\n';
      } else {
        if (l % b != 0) l = l / b + 1;
        else l = l / b;
        cout << n - l << '\n';
      }
    }
  }
}


