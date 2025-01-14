#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    if (n==1) {
      cout << 1 << '\n';
      continue;
    }
    ll act = 1;
    ll ans=1;
    while (act < n) {
      ans++;
      act = 2 * (act+1);
    }
    cout << ans << '\n';
  }
  return 0;
}


