#include <bits/stdc++.h> 
using namespace std;
int arr = 0;

int main () {
  int n;
  while (scanf("%d", &n) != EOF) {
    vector<int> v;
    for (int i = 0; i < n; i++) {
      int esc;
      scanf("%d", &esc);
      v.push_back(esc);
    }
    for (int i = 0; i < n - 1; i++) {
      int dif = abs( v[i] - v[ i + 1 ] );
      if (dif < n)
        arr |= (1<<dif);
    }
    if ((1<<n) - 2 == arr)
      cout << "Jolly\n";
    else 
      cout << "Not jolly\n";
  }
  //cout << "ADIOS\n";
  return 0;
}

