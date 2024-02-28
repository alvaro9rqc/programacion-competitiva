#include <bits/stdc++.h> 
using namespace std;
int main () {
  int s, b, l, r;
  while (scanf("%d %d", &s, &b), (s != 0)) {
    int casos = b;
    vector <bool> v(s, true);
    //cout << v.size() << "Tamañoo\n";
    while (casos --) {
      scanf("%d %d", &l, &r);
      fill(v.begin() + l - 1, v.begin() + r, false);
      //for (int i = 0; i < v.size(); i++) {
      //  cout << " " << v[i]; 
      //}
      //cout << '\n';
      bool flag = true;
      for (int i = l - 2; i > -1; i--) {
        if (v[i]) {
          flag = false;
          printf("%d ", i + 1);
          break;
        }
      }
      if (flag)
        printf("* ");
      flag = true;
      for (int i = r; i < v.size(); i++) {
        if (v[i]) {
          flag = false;
          printf("%d\n", i + 1);
          break;
        }
      }
      if (flag)
        printf("*\n");
    }
    printf("-\n");
  }
  return 0;
}

