#include <bits/stdc++.h>
using namespace std; 
int main () {
  int n, c;
  long l, r, x;
  scanf("%d %ld %ld %ld\n", &n, &l, &r, &x);
  vector <int> v;
  while (scanf("%d", &c) == 1) {
    v.push_back(c);
  }
  long count;
  for (int m = 0; m < (1<<n); m++) {
    long sum = 0; 
    int max, min;
    max = 0;
    min = 1000000;
    for (int i = 0; i < n; i++) {
      if (m & (1<<i)) {
        sum += v[i];
        if (v[i] > max) max = v[i];
        if (v[i] < min) min = v[i];
        //printf("%ld, %d, %d\n", sum, max, min);
      }
    }
    if (l <= sum && sum <= r && max - min >= x) count++;
  }
  printf ("%ld\n", count);

  return 0;
}
