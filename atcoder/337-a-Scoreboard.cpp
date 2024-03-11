#include <bits/stdc++.h> 
using namespace std;
int main () {
  int n, x, y;
  int ta = 0, ao = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &x, &y); 
    ta += x;
    ao += y;
  }
  string r = (ta > ao) ? "Takahashi":"Aoki";
  if (ta == ao) r = "Draw";
  cout << r << '\n';
  return 0;
}

