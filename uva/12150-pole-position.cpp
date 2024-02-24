#include <bits/stdc++.h> 
using namespace std;
int main () {
  int n, c, p; 
  while (scanf("%d", &n) == 1 && (n != 0)) {
    bool f = true;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++) {
      scanf("%d %d", &c, &p);
      if (0 <= i + p && i + p < n && v[i + p] == 0) {
        v[i + p] = c;
      } else { f = false; continue; }
    }
    if (f) {
      cout << v[0];
      for (int i = 1; i < n; i++) 
        printf(" %d", v[i]);
    } else printf("%d", -1);
    printf("\n");
  }
  return 0;
}

