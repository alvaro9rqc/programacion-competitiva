#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  while (t--) {
    ll n; cin >> n;
    ll sum=0;
    vector<ll> r1(n);
    vector<ll> r2(n);
    for (ll i = 0; i < n; ++i) {
      cin >> r1[i];
    }
    for (ll i = 0; i < n; ++i) {
      cin >> r2[i];
    }
    ll e=0;
    ll esum = -2000000;
    for (ll i = 0; i < n; ++i) {
      if (r2[i]<r1[i]) {
        sum+=r1[i];
      }else sum += r2[i];
      if (esum < (r2[i]+r1[i])) {
        esum = (r2[i]+r1[i]);
        e = i;
      }
    }
    if (r2[e]<r1[e]) sum+=r2[e];
    else sum += r1[e];
    cout << sum <<'\n';
  }
  return 0;
}


