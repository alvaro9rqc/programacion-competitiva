#include <bits/stdc++.h>
using namespace std;
int main () {
  int result;
  int n;
  scanf("%d", &n);
  result = ceil(sqrt(n));
  for (int i = 1; i < ceil(sqrt(n)) + 1; i++) {
    int x = i * i;
    int ans = 0;
    if (x - n >= 0)
      ans = x - n;
    else {
      int a, b, y;
      a = floor(sqrt(n - x));
      b = ceil(sqrt(n - x));
      y = min(a, b);
      ans = abs(x + y*y - n);
    }
    result = min(result, ans);
    //cout << ans << "-" << result << '\n';
    //cout << i << '\n';
  }
  cout << result << '\n';

  return 0;
}
