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
    int m = alf['M' - 'A'] / 1;
    if (alf['A' - 'A'] / 3 < m) m = alf['A' - 'A'] / 3;
    //if (alf['M' - 'A'] / 1 < m) m = alf['M' - 'A'] / 1;
    if (alf['R' - 'A'] / 2 < m) m = alf['R' - 'A'] / 2;
    if (alf['G' - 'A'] / 1 < m) m = alf['G' - 'A'] / 1;
    if (alf['I' - 'A'] / 1 < m) m = alf['I' - 'A'] / 1;
    if (alf['T' - 'A'] / 1 < m) m = alf['T' - 'A'] / 1;
    //right, I need to know how many margarita are there
    cout << m << '\n';
  }
  return 0;
}

