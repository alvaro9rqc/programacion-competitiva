#include <bits/stdc++.h> 
using namespace std;
int main () {
  char c;
  int n; scanf("%d\n", &n);
  while (n--) {
    stack <char> pila;
    string ecu;
    //read:
    string help;
    string in;
    while (getline(cin, help) && !help.empty()) {
      in.push_back(help[0]);
    } 
    //operation:
    for (int i = 0; i < in.size(); i++) {
      //operand
      if ('0' <= in[i] && c <= '9') {
        ecu.push_back(in[i]);
        continue;
      }
      //open bracket
      if (in[i] == '(') {
        pila.push(in[i]);
        continue;
      }
      //close bracket
      if (in[i] == ')') {
        while (pila.top() != '(') {
          ecu.push_back(pila.top());
          pila.pop();
        }
        pila.pop();
        continue;
      }
      //operator
      if (in[i] == '/' || in[i] == '*') {
        while (!pila.empty() &&pila.top() != '(' && ( pila.top() == '/' || pila.top() == '*' )) {
          ecu.push_back(pila.top());
          pila.pop();
        }
        pila.push(in[i]);
        continue;
      }
      if (in[i] == '+' || in[i] == '-') {
        while (!pila.empty() && pila.top() != '(') {
          ecu.push_back(pila.top());
          pila.pop();
        }
        pila.push(in[i]);
        continue;
      }
    }
    //the end;
    while (!pila.empty()) {
      ecu.push_back(pila.top());
      pila.pop();
    }
    cout << ecu << "\n";
    if (n) cout << '\n';
  }
  return 0;
}

