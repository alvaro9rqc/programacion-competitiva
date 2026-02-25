#include <bits/stdc++.h> 
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main () {
  ios_base::sync_with_stdio(false);
  long n; long m;
  cin >> n >> m;
  vector<pair<long, long>> v(m);
  for (long i = 0; i < m; ++i) {
    cin >> v[i].first;
  }
  for (long i = 0; i < m; ++i) {
    cin >> v[i].second;
  }
  sort(v.begin(), v.end());
  long sum = 0;
  long acsum = 0;
  for (long i = 0; i < m; ++i) {
    if (sum < v[i].first -1) {
      cout << -1 << '\n';
      return 0;
    }
    sum += v[i].second;
    acsum += v[i].first * v[i].second;
  }
  long t = ( n*(n+1) ) / 2;
  if (sum != n) cout << -1 << '\n';
  else cout <<  t- acsum << '\n';
}


