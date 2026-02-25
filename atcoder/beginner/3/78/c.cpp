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
  vector<ll> a(n);
  for (ll i = 0; i < n; ++i) {
    cin >> a[i];
  }
  unordered_map<ll, ll> m;
  for (ll i = 0; i < n; ++i) {
    if (m.find(a[i]) == m.end()) {
      cout << -1 << ' ';
    } else 
      cout << m[a[i]] << ' ';
    m[a[i]] = i+1;
  }
  cout << '\n';
  return 0;
}


