#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, m;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &n, &m);
    int r = ceil( (n-2) / 3.0 ) * ceil( (m-2) / 3.0 );
    printf("%d\n", r);
  }
  return 0;
}
