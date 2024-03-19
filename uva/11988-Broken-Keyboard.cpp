#include <bits/stdc++.h> 
using namespace std;
int main () {
  string s;
  while (getline(cin, s))  {
    //cout << s << '\n';
    string f = "", t;
    char m = 0; int j = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '[' || s[i] == ']') {
        t = s.substr(j, i - j);
        j = i + 1;
        if (m == '[') {
          f = t + f;
        } else if (m == ']') {
          f += t;
        } else 
          f = s.substr(0, i);
        m = s[i];
      }
    }
    if (m == '[') {
      f = s.substr(j) + f;
    } else if (m == ']') {
      f += s.substr(j);
    } 
    cout << f << '\n';
  } 
  return 0;
}

