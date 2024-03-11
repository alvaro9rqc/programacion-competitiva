#include <bits/stdc++.h> 
using namespace std;
int main () {
  char l;
  string a;
  bool flag = true;
  cin >> a;
  l = a[0];
  for (int i = 0; i < a.size(); i++) {
    if (a[i] < l) {
      flag = false;
      break;
    }
    l = a[i];
  }
  if (flag) 
    cout << "Yes" << '\n';
  else 
    cout << "No" << '\n';
  return 0;
}

