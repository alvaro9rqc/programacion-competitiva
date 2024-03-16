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
    //for (int i = 0; i < line.size(); i++) {
    //  cout << line[i] << "°"; 
    //}
    stack <pair<int, int>> pila;
    pila.push({line[0], 0});
    int flag = 1;
    //cout << line[12] << "-> "<< line.size() <<'\n';
    for (int i = 1; i < line.size(); i++) {
      if (line[i] < 0 /*&& !pila.empty() && line[i] > pila.top().first*/) {
        if (!pila.empty() && line[i] <= pila.top().first) {
          flag = 0; break;
        }
        pila.push({line[i], 0});
        continue;
      }
      if (!pila.empty() && line[i] * -1 == pila.top().first) {
        pila.pop();
        if (!pila.empty()) {
          pila.top().second += line[i];
          if (pila.top().first * -1 <= pila.top().second) {
            flag = 0;
            //cout << line[i] << "DX\n";
            //cout << pila.top().first << "°" << pila.top().second << '\n';
            break;
          }
        } 
        continue;
      }
      //cout << line[i] << "DX\n";
      //cout << "second\n";
      //cout << line[i] << " o " << i <<"DX\n";
      //cout << pila.top().first << "°" << pila.top().second << '\n';
      flag = 0;
      break;
    }
    if (!pila.empty()) flag = 0;
    if (flag) printf(":-) Matrioshka!\n");
    else printf(":-( Try again.\n");
    line.clear();
    if (dumy == '\n') 
    {
      //cout << "fin\n";
      continue;
    }
    //cout << '\n';
  }
  return 0;
}

