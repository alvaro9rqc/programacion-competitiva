#include <bits/stdc++.h> 
using namespace std;
unordered_set<int>& cal() {
  static unordered_set<int> s;
  for (int i = 1; pow(i, 6) < 100000000; i++) {
    s.insert(pow(i, 6)); 
  }
  return s;
}
int main () {
  ios_base::sync_with_stdio(false);
  unordered_set<int>& s = cal();
  int n; 
  while (cin>>n) {
    if (n == 0) break;
    if (s.find(n) == s.end())
      cout << "Ordinary\n";
    else cout << "Special\n";
  }
  return 0;
}


