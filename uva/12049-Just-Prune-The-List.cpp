#include <bits/stdc++.h> 
using namespace std;
//learning:
//como declarar un unordered_map de tamaño específico
int main () {

  int t, m, n; scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &n, &m);
    unordered_map <int, int> mm;
    unordered_map <int, int> nn;
    for (int i = 0; i < n; i++) {
      int v; scanf("%d", &v) ;
      if (nn.find(v) == nn.end()) 
        nn[v] = 1;
      else 
        nn[v] = nn[v] + 1;
    }
    for (int i = 0; i < m; i++) {
      int v; scanf("%d", &v) ;
      if (mm.find(v) == mm.end()) 
        mm[v] = 1;
      else 
        mm[v] = mm[v] + 1;
    }
    long long c = 0;
    unordered_map <int, int> & max = (mm.size() > nn.size())? mm:nn;
    unordered_map <int, int> & min = (mm.size() < nn.size())? mm:nn;

    for (const auto & p : max) {
      if (min.find(p.first) == min.end()) 
        c += p.second;
      else 
        c += abs(p.second - min[p.first]);
    }
    printf("%lld\n", c);
  }
  return 0;
}

