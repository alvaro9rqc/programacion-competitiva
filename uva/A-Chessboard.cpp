#include <bits/stdc++.h> 
using namespace std;
int main () {
  int t, n;
  scanf("%d", &t);
  //cin >> t;
  while (t--) {
    //cin >> n;
    scanf("%d", &n);
    if (n == 1)
    {
      printf("0.000\n\n");
      //cout << '0' << "\n\n";
      continue;
    }
    printf("%.3f\n\n", 4 * ( n - 1 ) + pow( n -2, 2 ) * sqrt(2));// <<  << "\n\n";
  }
  return 0;
}


