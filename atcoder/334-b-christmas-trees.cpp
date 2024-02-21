#include <bits/stdc++.h> 
using namespace std;
long trees(long d, long m) {
  return d / m;
}
int main () {
  long a, m, l, r;
  cin >> a >> m >> l >> r;
  int bonus = (l <= a && a <= r ) ? 1 : 0; 
  l -= a;
  r -= a;
  long t1, t2;
  t1 = trees(l, m);
  t2 = trees(r, m);
  cout << t2 - t1  + bonus << '\n';
  return 0;
}
