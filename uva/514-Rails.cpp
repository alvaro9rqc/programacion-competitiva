#include <bits/stdc++.h> 
using namespace std;
int main () {
  int n, b = 1;
  while (scanf("%d", &n) != EOF && n != 0) {
    if(!b) printf("\n");
    //printf("salto de bloque: %d\n", n);
    //esto representa cada linea del bloque
    while (scanf("%d", &b), b != 0) {
      //cout << "primer número: " << b << '\n';
      stack<int> s;
      int turn = 1, sca = n - 1;
      while (b != turn) {
        s.push(turn);
        turn++;
      }
      while (sca > 0 && turn <= n) {
        scanf("%d", &b);
        sca--;
        //revisar stack
        while (!s.empty() && b == s.top()) {
          s.pop();
          if (sca) scanf("%d", &b);
          //cout << "segundo número: " << b << '\n';
          sca--;
        }
        turn++;
        while (b != turn && turn < n + 1) {
          turn++;
        }
      }
      scanf("%*[^\n]");
      if (s.empty())
        printf("Yes\n");
      else 
        printf("No\n");
    }
  }
  return 0;
}

