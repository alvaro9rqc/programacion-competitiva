#include <bits/stdc++.h> 
using namespace std;
int isOperator(const int& c) {
  switch (c) {
    case '+':
      return 1;
    case '-':
      return 1;
    case '*':
      return 1;
    case '/':
      return 1;
    default:
      return 0;
  }
}
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
      }
    }
    while (scanf("%c", &c) != EOF){
      if (c == '\n')
        break;
      scanf("%*c");
      //cout << c << "-";
      if ( '0' <= c && c <= '9'  ) {
        ecu.push_back(c);
        continue;
      }
      if (c == '(') {
        pila.push(c);
        continue;
      }
      if (c == ')') {
        while (!pila.empty() && pila.top() != '(') {
          ecu.push_back(pila.top());
          pila.pop();
        }
        pila.pop();
        continue;
      }
      //only if this is an operator
      if (c == '*' || c == '/') {
        while (!pila.empty()) {
          char aux = pila.top();
          if (aux != '(' && (aux == '*' || aux == '/')) {
            ecu.push_back(aux);
            pila.pop();
          } else {
            break;
          }
        }
        pila.push(c);
        continue;
      }
      //if c == + or -
      while (!pila.empty()) {
        if (pila.top() != '(') {
          ecu.push_back(pila.top());
          pila.pop();
        } else {
          break;
        }
      }
      pila.push(c);
    }
    while (!pila.empty()) {
      ecu.push_back(pila.top());
      pila.pop();
      cout << ecu << '\n';
    }
    if (n != 0) printf("\n");
    cout << '\n';
  }
  return 0;
}

