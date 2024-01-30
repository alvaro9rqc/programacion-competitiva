#include <bits/stdc++.h>
int main () {
  int n = 3;
  int a[n] = {1, 2, 3};
  int s = 3;
  for (int m = 0; m < (1 << n); m++) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
      if (m & (1<<i)) sum += a[i];
    }
    if (sum == s) {
      printf("sí hay  %d\n", sum); 
      return 0;
    }
  }
  printf ("no hay\n");
  return 0;
}
