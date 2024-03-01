#include <bits/stdc++.h> 
using namespace std;
int main () {
  int n; scanf("%d\n", &n);
  stack<int> s;
  //int m;
  //scanf("%d", &m);
  //s.push(m); n--;
  while (n--) {
    int m;
    scanf("%d", &m );
    if (!s.empty() && (s.top() + m) % 2 == 0) 
      s.pop();
    else 
      s.push(m);
  }
  cout << s.size() << '\n';
  return 0;
}

