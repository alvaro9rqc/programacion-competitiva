#include <bits/stdc++.h> 
using namespace std;
int main () {
  int a, b, c,n;
  scanf("%d", &n);
  while (n--) {
    scanf("%d %d %d", &a, &b, &c);
    bool f = false;
    int x, y, z;
    int r = (int)( ceil(sqrt(c)) );
    for (x=-r; x<r; ++x) 
    {
      int l = c - x*x;
      for(y = -l; y < l; ++y) {
        z = a - x - y;
        if (
            (x != y && z != y && x !=z) &&
            (x*z*y == b) &&
            (x*x + y*y + z*z == c)
           ) {
          f = true;
          goto label;
        }
      }
    }
label:
    if (f) printf("%d %d %d\n", x, y,z);
    else printf("No solution.\n");
  }
}

