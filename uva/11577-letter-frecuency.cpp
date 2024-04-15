#include <bits/stdc++.h> 
using namespace std;
int main () {
  int n;
  scanf("%d", &n);
  string line;
  while (n--) {
    getline(cin, line);
    int alf ['z' - 'a' + 1] = {0};
    int max = 0;
    for (char &x : line) {
      x = tolower(x);
      if (!('a' <= x && x <= 'z')) continue;
      alf[x - 'a'] ++;
    }

  }
  return 0;
}

