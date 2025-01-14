#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  unordered_set<ll> s;
  for (ll i = 1; i < 101; i+=2) {
    s.insert(i*i);
  }
  ll t, n, a;
  cin >> t;
  while(t--) {
    ll d = 0;
    ll sum =0;
    cin >> n;
    for (ll i = 0; i < n; ++i) {
      cin >> a;
      sum += a;
      if (s.find(sum) != s.end()) ++d;
    }
    cout << d << '\n';
  }
  return 0;
}


