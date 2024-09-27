#include <bits/stdc++.h> 
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main () {
  ios_base::sync_with_stdio(false);
  long t, g, l;
  cin >> t;
  while (t--) {
    cin >> g >> l;
    if (l % g == 0) {
      cout << g << ' ' << l << '\n';
    }
    else cout << -1 << '\n';
  }
  return 0;
}


