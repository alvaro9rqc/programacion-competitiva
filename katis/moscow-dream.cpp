#include <bits/stdc++.h>
using namespace std; 
int main () {
  int a, b, c, n; scanf("%d %d %d %d", &a, &b, &c, &n);
  printf(((a >0) && (b>0) && (c>0) && (a+b+c >= n) && (n>2)) ? "YES\n" : "NO\n");
  return 0;
}
