#include <bits/stdc++.h>
using namespace std; 
int main () {
  int t, n;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    printf("%d\n", abs( ( 315*n +36962 ) % 100 / 10 ));
  }
  return 0;
}
