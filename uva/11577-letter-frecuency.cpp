#include <bits/stdc++.h> 
using namespace std;
int main () {
  int n;
  scanf("%d\n", &n);
  string line;
  while (n--) {
    getline(cin, line);
    int alf ['z' - 'a' + 1] = {0};
    int max = 0;
    for (char &x : line) {
      x = tolower(x);
      if (!('a' <= x && x <= 'z')) continue;
      if (++alf[x - 'a'] > max) max = alf[x - 'a'];
    }
    string s;
    for (int i = 0; i < ('z' - 'a' + 1); ++i) {
      if (alf[i] == max) s.push_back((char)(i + 'a'));
    }
    cout << s << '\n';
  }
  return 0;
}

