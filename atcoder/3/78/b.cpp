#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n;
  cin >> n;
  vector<pair<ll,ll>> N(n);
  for (ll i = 0; i < n; ++i) {
    cin >> N[i].first;
    cin >> N[i].second;
  }
  ll q;
  cin >> q;
  for (ll i = 0; i < q; ++i) {
    ll t, d; cin >>t>> d; t--;
    ll m = d % N[t].first;
    if (m > N[t].second) {
      ll ans = d + N[t].first - m + N[t].second;
      cout << ans << '\n';
    } else {
      ll res = N[t].second - m;
      cout << d + res << '\n';
    }

  }

  return 0;
}


