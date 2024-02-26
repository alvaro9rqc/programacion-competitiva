#include <bits/stdc++.h> 
using namespace std;
int main () {
  int n;
  char l;
  scanf("%d%*c%*c", &n);
  while (n--) {
    scanf("%c%*c", &l);
    cout << n << l << ":D"<< '\n';
    vector<vector<int>> al;
    vector<bool> dfs_num;
    char a, b;
    while (scanf("%c", &a) != EOF && (a != '\n')) {
      scanf("%c%*c", &b);
      cout << a << b << '\n';
    }
    //cout << al[arist-1][0];
  }

  return 0;
}

