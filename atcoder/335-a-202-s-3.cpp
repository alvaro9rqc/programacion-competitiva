#include <bits/stdc++.h> 
using namespace std;
int main () {
  string s; cin >> s;
  int i = s.size();
  s[i - 1] = '4';
  //s.back() = '4';
  cout << s << '\n';
  return 0;
}

