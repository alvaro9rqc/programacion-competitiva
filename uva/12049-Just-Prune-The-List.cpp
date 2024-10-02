#include <bits/stdc++.h> 
using namespace std;
//learning:
//como declarar un unordered_map de tamaño específico
int main () {

  int t, m, n; scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &n, &m);
    unordered_map <int, int> a(n);
    unordered_map <int, int> b(m);
    int dummy;
    for (int i = 0; i < n; ++i) {
      scanf("%d", &dummy );
      if (a.find(dummy) != a.end()) {
        a[dummy] += 1;
      } else 
        a[dummy]  = 1;
    }
    for (int i = 0; i < m; i++) {
      scanf("%d", &dummy );
      if (a.find(dummy) != a.end()) {
        a[dummy] -= 1;
      } else if (b.find(dummy) != b.end()){
        b[dummy] += 1;
      } else {
        b[dummy] = 1;
      }
    }
    long sum = 0;
    for (auto & par : a) {
      sum += abs(par.second);
    }
    for (auto & par : b) {
      sum += par.second;
    }
    printf("%ld\n", sum);
  }
  return 0;
}

