#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

ll era(ll n) {
  while(n % 10 == 0)
    n /= 10;
  return n;

}
const ll lim = 1000000000;
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, m;
  while (cin >> n >> m) {
    ll ans = 1;
    ll x;
    ll rep = n - m;
    for (ll i = n; i > rep; --i) {
      x = era(i);
      ans *= x;
      ans = era(ans);
      ans %= lim;

    }
    cout << era(ans) % 10 << '\n';
  }
  return 0;
}


