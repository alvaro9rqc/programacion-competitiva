#include <bits/stdc++.h> 
using namespace std;
int main () {
  int n, b;
  while (scanf("%d", &n) != EOF && n != 0) {
    while (scanf("%d", &b), b != 0) {
      //cout << "b: " << b << '\n';
      int pen = n, i = n - 1; 
      stack<int> s;
      if (b == pen)
        pen --;
      else 
        s.push(b);
      while (i--) {
        scanf("%d", &b);
        if (b == pen) {
          //cout << "igual: " << b << '\n';
          pen--;
          while (!s.empty() && s.top() == pen) {
            //cout << "top: " << s.top() << '\n';
            s.pop();
            pen--;
          }
        } else {
          //cout << "agragar: " << b << '\n';
          s.push(b);
        }
      } 
      if (s.size() == 0 )
        printf("Yes\n");
      else 
        printf("No\n");
    }
    if (b != 0)
      printf("\n");
  }
  return 0;
}

