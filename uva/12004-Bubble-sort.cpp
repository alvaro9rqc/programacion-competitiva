#include <bits/stdc++.h> 
using namespace std;
int main () {
  ios_base::sync_with_stdio(false);
  long t, n;
  cin >> t;
  long i =0;
  while (i++<t) {
    cin >> n;
    n = n*n - n;
    if (n%4==0) cout << "Case " << i << ": " << n/4 << '\n';
    else if (n % 2 == 0) cout << "Case " << i << ": " << n/2 << "/2" << '\n';
    else cout << "Case " << i << ": " << n << "/4" << '\n';
  }
  return 0;
}


