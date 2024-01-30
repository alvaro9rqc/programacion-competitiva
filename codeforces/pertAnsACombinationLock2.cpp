#include <bits/stdc++.h>
using namespace std;
int main () {
  int n, inp;
  scanf("%d", &n);
  vector <int> v1;
  while ( scanf("%d", &inp) == 1 ) {
    v1.push_back(inp);
  }
  for (int m = 0; m < (1<<n); m++) {
    int r = 0;
    for (int i = 0; i < n; i++) {
      if ( m & (1<<i) ) r += v1[i];
      else r -= v1[i];
    }
    printf("%d\n", r);
    if (r % 360 == 0) {
      printf("YES\n");
      return 0;
    }
  }
  printf("NO\n");
  return 0;
}
