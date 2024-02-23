#include <bits/stdc++.h> 
using namespace std;
long piso(long a, long b) {
  long r = (a % b + b) % b;
  return (a - r) / b;
}
int main () {
  long a, m, l, r;
  cin >> a >> m >> l >> r;
  l -= a;
  r -= a;
  //long t1, t2;
  //t1 = floor(l / m);
  //t2 = floor(r / m);
  //cout << t2 - t1  << '\n';
  cout << piso (r, m) - piso(l - 1, m) << '\n';
  return 0;
}
