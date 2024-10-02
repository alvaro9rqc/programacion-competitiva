#include <bits/stdc++.h> 
using namespace std;
int main () {
  ios_base::sync_with_stdio(false);
  long t, n, m; scanf("%ld", &t);
  while (t--) {
    scanf("%ld %ld", &n, &m);
    printf("%ld\n", (2*m*n - n - n*n)/2);
  }
  return 0;
}


