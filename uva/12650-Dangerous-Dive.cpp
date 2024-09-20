#include <bits/stdc++.h> 
using namespace std;
int main () {
  ios_base::sync_with_stdio(false);
  int r, n, persona;
  vector<int> v;
  string s;
  while (cin >> n >> r) {
    v.assign(n, true);
    if (n == r) {
      cout << "*\n";
      getline(cin, s);
      getline(cin, s);
      continue;
    }
    for (int i = 0; i < r; i++) {
      cin >> persona;
      v[persona-1] = false;
    }
    for (int i = 0; i < n; i++) {
      if (v[i]) cout << i + 1 << " ";
    }
    cout << '\n';
  }
  return 0;
}


