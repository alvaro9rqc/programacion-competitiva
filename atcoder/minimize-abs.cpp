#include <bits/stdc++.h>
using namespace std;
int main() {
  long n, l, r, min, x, a;
  scanf("%ld %ld %ld ", &n, &l, &r);
  while (n--) {
    scanf("%ld", &a);
    if (a < l) {
      printf("%ld ", l);
      continue;
    }
    if (a > r) {
      printf("%ld ", r);
      continue;
    }
    printf("%ld ", a);
  }
  printf("\n");
  return 0;
}
