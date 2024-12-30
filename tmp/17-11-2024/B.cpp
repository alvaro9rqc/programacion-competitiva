#include <bits/stdc++.h> 
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long t, k;
  cin >> t;
  while (t--) {
    cin >> k;
    vector<long> v(k);
    unordered_set<long> s;
    for (long i = 0; i < k; ++i) {
      cin >> v[i];
    }
    for (long i = 0; i < k; ++i) {
      if (s.find(v[i]) != s.end()) {
        cout << v[i] << ' ' << (k-2) / v[i] << '\n';
        break;
      }
      if ((k-2) % v[i] == 0) 
        s.insert((k-2) / v[i]);
    }
  }
  return 0;
}


