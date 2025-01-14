#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t; cin >> t;
  while (t--) {
    ll n; cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
      cin >> a[i];
    }
    ll im, pa;
    im=pa=n/2;
    if(n&1)im++;
    ll sumi, sump;
    sumi=sump=0;
    for (ll i = 0; i < n; i+=2) {
      sumi+=a[i];
    }
    for (ll i = 1; i < n; i+=2) {
      sump+=a[i];
    }
    if (sumi % im == 0 and sump % pa == 0
        and sumi / im == sump / pa) 
      cout << "YES\n";
    else cout << "NO\n";
  }
  return 0;
}


