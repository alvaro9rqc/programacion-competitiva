#include <bits/stdc++.h>
using namespace std;
int main() {
  int i = 0;
  long n; scanf("%ld", &n);
  for ( i; i < n; i++) {
    if (n & (1L<<i)) break;
  }
  cout << i << '\n';
  return 0;
}
