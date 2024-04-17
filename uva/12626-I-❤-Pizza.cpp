#include <bits/stdc++.h> 
using namespace std;
int main () {
  int n; scanf("%d\n", &n);
  string line;
  while (n--) {
    int alf['Z' - 'A' + 1] = {0};
    getline(cin, line);
    for (char &x : line) 
      alf[x - 'A']++;
    //right, I need to know how many margarita are there
  }
  return 0;
}

