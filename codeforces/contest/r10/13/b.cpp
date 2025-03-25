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
  ll t;
  cin >> t;
  while(t--){
    ll n, x;
    cin >> n >> x;
    vll a(n);
    for(auto& e: a) cin >> e;
    sort(a.rbegin(),a.rend());
    ll ct=1;
    ll ans =0;
    for (auto i = 0; i < n; ++i) {
      ll pw = ct*a[i];
      if (pw >= x) {
        ++ans;
        ct=1;
      } else {
        ct++;
      }
    }
    cout << ans << '\n';
  }
}


