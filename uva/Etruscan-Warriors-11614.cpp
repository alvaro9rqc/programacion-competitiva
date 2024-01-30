#include <bits/stdc++.h>
using namespace std;
int main() {
  long m, n;
  scanf("%ld", &m);
  while (m--) {
    scanf("%ld", &n);
    printf("%d\n", int((-1 + sqrt(1 + 8*n)) / 2));
  }
  return 0;
}
