#include <bits/stdc++.h> 
using namespace std;
int main () {
  int m, n;
  while (true) {
    scanf("%d %d", &n, &m);
    if (m + n == 0) break;
    unordered_set<int> maps (n);
    int sc;
    for (int i = 0; i < n; i++) {
      scanf("%d", &sc); maps.insert(sc);
    }
    int count = 0;
    for (int i = 0; i < m; i++) {
      scanf("%d", &sc);
      if (maps.find(sc) != maps.end()) 
        ++count;
    }
    printf("%d\n", count);
  }
  return 0;
}

