#include <bits/stdc++.h> 
using namespace std;
int main () {
  int n;
  char l;
  scanf("%d\n\n", &n);
  while (n--) {
    scanf("%c\n", &l);
    cout << n << l << ":D"<< '\n';
    vector<vector<int>> al;
    vector<bool> dfs_num;
    char a, b;
    while (scanf("%c", &a) != EOF && (a != '\n')) {
      scanf("%c\n", &b);
      cout << a << b<< "esc" << '\n';
    }
    //cout << al[arist-1][0];
  }

  return 0;
}

