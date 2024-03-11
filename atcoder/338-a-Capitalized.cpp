#include <bits/stdc++.h> 
using namespace std;
int main () {
  string a;
  cin >> a;
  bool primero;
  primero = 'A' <= a[0] && a[0] <= 'Z';
  bool seg = true;
  if (a.size() > 1) {
    for (int i = 1; i < a.size(); i++) {
      if (a[i] < 'a' || a[i] > 'z') {
        seg = false;
        break;
      } 
    }
  }
  if (primero && seg) 
    cout << "Yes\n";
  else 
    cout << "No\n";
  return 0;
}

