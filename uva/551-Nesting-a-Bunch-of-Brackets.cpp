#include <bits/stdc++.h> 
using namespace std;
char open[] = { '{', '[', '<' };
char closed[] = { '}', ']', '>' };

bool isOpen(const int& c) {
  int n = 3;
  while (n--) {
    if (open[n] == c) return true;
  }
  return false;
}

bool isClose(const int& c) {
  int n = 3;
  while (n--) {
    if (closed[n] == c) return true;
  }
  return false;
}

int main () {
  string line;
  //for (int i = 0; i < 3; i++) {
  //  cout << open[i] << "->" << (char)(open[i] + 2) << '\n'; 
  //}
  
  while (getline(cin, line)) {
    stack<char> pila;
    int count = 0;
    int pending = 0;
    int next = 0;
    int ok = 1;
    for (int i = 0; i < line.size(); i++) {
      count++;
      if (isOpen(line[i])) {
        pila.push(line[i]);
        continue;
      }
      if (isClose(line[i])) {
        if (!pila.empty() && pila.top() == line[i]-2 ){
            pila.pop();
            continue;
        } else {
          //printf("NO %d\n", count);
          //cout << "<<" << pila.top() << '\n';
          ok = 0;
          break;
        }
      }
      if (line[i] == '(') {
        pending = 1;
        pila.push('(');
        continue;
      }
      if (line[i] == ')') {
        if (next) {
          count--;
          next = 0;
          if (!pila.empty() && pila.top() == 'a' ){
            pila.pop();
            continue;
          } else {
            //printf("NO %d\n", count);
            ok = 0;
            break;
          }
        } else {
          if (!pila.empty() && pila.top() == '(' ){
            pila.pop();
            continue;
          } else {
            //printf("NO %d\n", count);
            ok = 0;
            break;
          }   
        }
      }
      if (line[i] == '*') {
        if (pending) {
          pending = 0;
          pila.pop();
          pila.push('a');
          count--;
          continue;
        }
        next = 1;
      }
    }
    if (pila.empty() && ok) 
      printf("YES\n");
    else 
    {
      printf("NO %d\n", count);
      //cout << pila.top() << '\n';
    }
  }
  return 0;
}

