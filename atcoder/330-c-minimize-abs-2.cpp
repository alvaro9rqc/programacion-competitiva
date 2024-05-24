#include <bits/stdc++.h> 
using namespace std;
int main () {
  double d; scanf("%lf", &d);
  double r = sqrt(d);
  double l = ceil(r);
  if (r == l) {
    cout << 0 <<'\n'; return 0;
  };
  long mini = abs(d - l*l);
  for (long i = 0; i <= l + 1; ++i) {
    long y1 = floor(sqrt(abs(d - i*i)));
    long y2 = ceil(sqrt(abs(d - i*i)));
    long dif = min(abs(d - y1*y1 - i*i), abs(d - y2*y2 - i*i));
    if (dif < mini) mini=dif;
  }
  cout << mini << '\n';


  return 0;
}

