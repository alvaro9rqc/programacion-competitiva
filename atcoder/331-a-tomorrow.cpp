#include <bits/stdc++.h> 
using namespace std;
int main () {
  int M, D, y, m, d;
  cin >> M >> D >> y >> m >> d;
  int r = 0;
  d++;
  if ( d > D ) {
    d = 1;
    r++;
  }
  m += r;
  if (m > M) {
    y++;
    m = 1;
  }
  printf("%d %d %d\n", y, m, d);

  return 0;
}

