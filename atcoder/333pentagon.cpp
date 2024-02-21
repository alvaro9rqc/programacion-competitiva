#include<bits/stdc++.h>
using namespace std;
int dis(char x, char y) {
  //printf("%c%c\n", x, y);
  return abs(x - y) % 3;
}
int main () {
  char a,b,c,d;
  scanf("%c%c\n", &a, &b);
  scanf("%c%c", &c, &d);
  if (dis(a, b) == dis(c, d))
    cout << "Yes\n";
  else 
    cout << "No\n";
  return 0;
}

