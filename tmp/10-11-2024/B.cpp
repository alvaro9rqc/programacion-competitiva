#include <bits/stdc++.h> 
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main () {
  ios_base::sync_with_stdio(false);
  long t, l, k, n;
  cin >> t;
  while (t--) {
    cin >> n>> l >> k;
    if (l == 0 and k == 0) {
      if (n == 1) cout << "0\n";
      if (n == 2) cout << "1\n";
      else cout << "-1\n";
    } else if (l == 0) {
      if (k < n - 2) {
        cout << "-1\n";
      } else {
        if (k >= n) cout << n << '\n';
        else cout << n-1<<'\n';
      }
    } else if (k == 0) {
      if (l == 1) cout << "0\n";
      else {
        long i = (n-1) / l;
        cout << n - i - 1 << '\n';
      }
    } else {
      long i = ( (n-1-k) / l );
      if (n -1 -k < 0) i = -1;
      //cout << "--> " << i << '\n';
      if (i < 0) cout << n << '\n';
      else cout << n - i - 1 << '\n';
    }
  }
  return 0;
}


