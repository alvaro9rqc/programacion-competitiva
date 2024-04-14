#include <bits/stdc++.h> 
using namespace std;
int main () {
  int n, m;
  while (1) {
    scanf("%d %d", &n, &m);
    if (n == 0 && m == 0) break;
    long sumppa = 0;
    double avr = 0;
    vector<vector< pair<int, int>>> graph(n);
    for (int i = 0; i < m; i++) {
      int v1, v2, w;
      scanf("%d %d %d", &v1, &v2, &w);
      //printf("leidos: %d, %d, %d\n", v1, v2, w);
      v1--; v2--;
      graph[v1].emplace_back(v2, w);
      graph[v2].emplace_back(v1, w);
      sumppa += w;
    }
    avr= (double)sumppa / (double)m;
    //printf("el promedio será : %ld / %d = %f\n", sumppa, m, avr);
    int cities = 0;
    for (auto vertex : graph) {
      long weight = 0;
      double avrw;
      for (auto v : vertex) {
        weight += v.second;
      }
      avrw = (double) weight / (double)vertex.size();
      if (avrw > avr) 
      {
        cities++;
      }
    }
    printf("%d\n", cities);
  }
  return 0;
}

