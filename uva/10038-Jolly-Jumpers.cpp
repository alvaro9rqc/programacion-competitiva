#include <bits/stdc++.h> 
using namespace std;
int main () {
  int n;
  while (scanf("%d", &n) != EOF) {
    vector<int> v;
    vector<int> aws(n, 0);
    for (int i = 0; i < n; i++) {
      int esc;
      scanf("%d", &esc);
      v.push_back(esc);
    }
    for (int i = 0; i < n - 1; i++) {
      int dif = abs( v[i] - v[ i + 1 ] );
      if (dif < n)
        aws[dif] = 1;
    }
    bool f = true;
    for (int i = 1; i < n; i++) {
      if (aws[i] == 0)
        f = false;
    }
    if (f)
      cout << "Jolly\n";
    else cout << "Not jolly\n";
  }
  return 0;
}

