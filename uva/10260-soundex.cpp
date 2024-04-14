#include <bits/stdc++.h> 
using namespace std;
//idea: pues haces una función
//que te tome los arrays y un valor que asignaras a esas posisiones
//si no, todo lo demás será 0.
int sounds['Z' - 'A' + 1] = {0};
void transf (string a, int i) {
  for (char c : a) {
    sounds[c - 'A'] = i;
  }
}
int main () {
  string s1 = "BFPV";
  string s2 = "CGJKQSXZ";
  string s3 = "DT";
  string s4 = "L";
  string s5 = "MN";
  string s6 = "R";
  transf(s1, 1);
  transf(s2, 2);
  transf(s3, 3);
  transf(s4, 4);
  transf(s5, 5);
  transf(s6, 6);
  string line;
  while (getline(cin, line)) {
    string ans = "";
    if (line.size() <= 0) continue;
    for (char c : line) {
      if (!('A' <= c && c <= 'Z')) continue;
      int s = sounds[c - 'A'];
      if (s && ans.back() - '1' + 1 != s)
        ans.append(to_string(s));
      else if (!s) 
        ans.push_back('\0');
    }
    cout << ans << '\n';
  }
  return 0;
}

