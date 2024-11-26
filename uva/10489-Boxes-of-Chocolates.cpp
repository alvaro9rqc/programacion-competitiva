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
    ll n, b, sum, k, idx;
    cin >> n >> b;
    sum = 0;
    for (auto i = 0; i < b; ++i) {
      idx = 1;
      cin >> k;
      ll l;
      for (auto j = 0; j < k; ++j) {
        cin >> l;
        idx = ( idx * (l % n) ) % n;
      }
      sum = ( sum + (idx % n) ) % n;
    }
    cout << sum << '\n';
  }
  return 0;
}


