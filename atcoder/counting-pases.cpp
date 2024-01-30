#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, l, a, i;
  i = 0;
  scanf("%d %d", &n, &l);
  while(n--) {
    scanf("%d", &a);
    if (a >= l) i++;
  }
  printf("%d\n", i);
  return 0;
}
