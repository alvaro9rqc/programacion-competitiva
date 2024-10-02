#include <bits/stdc++.h> 
using namespace std;
int main () {
  int n; scanf("%d", &n);
  char a[n] = {'o'};
  a[0] = 'L'; a[n - 2] = 'n'; a[n - 1] = 'g';
  cout << a << '\n';
  return 0;
}

