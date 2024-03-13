#include <bits/stdc++.h> 
using namespace std;
int main () {
  string line;
  int n; scanf("%d\n", &n);
  while (n--) {
    getline(cin, line);
    stack<char> pila;
    int ok = 1;
    for (int i = 0; i < line.size(); i++) {
      if (line[i] == '[' || line[i] == '(') {
        pila.push(line[i]);
        continue;
      }
      if (!pila.empty() && (pila.top() == line[i] - 2 || pila.top() == line[i] - 1)) {
        pila.pop();
      } else {
        ok = 0;
        break;
      }
    }
    if (ok && pila.empty()) 
      cout << "Yes\n";
    else 
      cout << "No\n";
  }
  return 0;
}

