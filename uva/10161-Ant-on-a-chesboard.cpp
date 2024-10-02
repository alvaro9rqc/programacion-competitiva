#include <bits/stdc++.h> 
using namespace std;
int main () {
  ios_base::sync_with_stdio(false);
  long n, r;
  while (cin >> n) {
    if (n == 0) break;
    r = sqrt(n);
    if (r % 2 == 0) 
      if (r*r == n) 
      {
        cout << r << " " << 1 << '\n';
      }
      else 
        if (n <= r*r + r + 1) cout << r +1 << " " << n - r*r << '\n';
        else cout << pow(r+1, 2)-n+1 << " " << r+1 << '\n';
    else 
      if (r*r == n) 
      {
        cout << 1 << " " << r << '\n';
      }
      else 
        if (n <= r*r + r + 1) cout << n-r*r << " " << r+1 << '\n';
        else cout << r+1 << " " << pow(r+1, 2) - n + 1 << '\n';
  }
  return 0;
}


