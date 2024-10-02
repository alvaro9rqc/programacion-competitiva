#include <bits/stdc++.h> 
using namespace std;
int main () {
  int a, b, c,n;
  scanf("%d", &n);
  while (n--) {
    scanf("%d %d %d", &a, &b, &c);
    bool f = false;
    int x, y, z;
    for (x = -100; x <= 100; ++x )
      for (y = -100; y <= 100; ++y )
        for (z = -100; z <= 100; ++z )
          if (
              (x != y && x != z && y !=z) &&
              (x + y + z == a) &&
              (x*y*z == b) &&
              (x*x + y*y + z*z == c)
             ) {
            f = true;
            goto salir;
          }
salir:
    if (f) printf("%d %d %d\n", x, y,z);
    else printf("No solution.\n");
  }
}

