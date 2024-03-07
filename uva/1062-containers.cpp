#include <bits/stdc++.h> 
using namespace std;
int main () {
  char cont;
  int caso = 1;
  while (true) {
    scanf("%c", &cont);
    if (cont == 'e') break;
    //cout << "el char: " << cont << '\n';
    vector<char> v;
    v.push_back(cont);
    while (true) {
      scanf("%c", &cont);
      if (cont == '\n') break;
      for (int i = 0; i < v.size(); i++) {
        if (cont <= v[i]) {
          v[i] = cont;
          //printf("se cambia:  %c\n", cont);
          cont = 0;
          break;
        } 
      }
      if (cont == 0) continue;
      v.push_back(cont);
      //cout << cont;
    }
    int size = v.size();
    printf("Case %d: %d\n", caso, size);
    caso++;
  }
  return 0;
}

