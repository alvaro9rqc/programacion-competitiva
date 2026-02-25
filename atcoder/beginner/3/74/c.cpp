#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<ll> k(n);
  ll ans=0;
  ll sum;
  for (auto i = 0; i < n; ++i) {
    cin >> k[i];
    ans += k[i];
  }
  sum = ans;
  ll ac=0;
  for (ll i = 0; i < (1ll << n); ++i) {
    ac = 0;
    for (ll j = 0; j < n; ++j) {
      if (i & (1ll << j)) {
        ac += k[j];
      }
    }
    ans = min(ans, max(ac, sum - ac));
  }
  cout << ans << '\n';
  return 0;
}


