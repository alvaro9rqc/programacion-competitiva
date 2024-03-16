#include <bits/stdc++.h> 
using namespace std;
int main () {
  char dumy;
  int n;
  vector <int> line;
  while (true) {
    if (scanf("%d%c", &n, &dumy) == EOF ) break;
    line.push_back(n);
    while (scanf("%d%c", &n, &dumy)) {
      line.push_back(n);
      if (dumy == '\n') break;
    }
    stack <pair<int, int>> pila;
    pila.push({line[0], 0});
    int flag = 1;
    for (int i = 1; i < line.size(); i++) {
      if (line[i] < 0 && !pila.empty() && line[i] > pila.top().first) {
        pila.push({line[i], 0});
        continue;
      }
      if (!pila.empty() && line[i] * -1 == pila.top().first) {
        pila.pop();
        if (!pila.empty()) {
          pila.top().second += line[i];
          if (pila.top().first * -1 <= pila.top().second) {
            flag = 0;
            break;
          }
        } 
        continue;
      }
      flag = 0;
      break;
    }
    if (!pila.empty()) flag = 0;
    if (flag) printf(":-) Matrioshka!\n");
    else printf(":-( Try again.\n");
    line.clear();
    if (dumy == '\n') 
    {
      continue;
    }
  }
  return 0;
}

