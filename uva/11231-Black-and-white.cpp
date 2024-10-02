#include <bits/stdc++.h> 
using namespace std;
int main () {
  ios_base::sync_with_stdio(false);
  long n , m , c;
  while (cin >> n >> m >> c) {
    if (m == 0 && n == 0 && c == 0) break;
    m -=7; n-=7;
    if (m < 1 && n < 1) cout << '0' << '\n';
    else {
      if (c == 1) {
        cout << (int)ceil(m*n*1.0/2) << '\n';
      } else cout << (int)floor( m*n/2  )<< '\n';
    }
  }
  return 0;
}


