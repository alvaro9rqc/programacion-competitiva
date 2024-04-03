#include <bits/stdc++.h> 
using namespace std;
void pri (int& a, const int& b, const string& s) {
  for (a; a < b; a++) {
    printf("%c", s[a]);
  }
}

int main () {
  string s;
  while (getline(cin, s))  {
    //cout << s << '\n';
    deque<pair<int, int>> ref;
    int j = 0; char m = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '[' || s[i] == ']') {
        if (m == '[') {
          ref.push_back({j, i});
        } else {
          ref.push_front({j, i});
        } 
        m = s[i];
        j = i + 1;
      }
    }
    if (m == '[') {
      ref.push_back({j, s.size()});
    } else if (m == ']') {
      ref.push_front({j, s.size()});
    } 
    while (!ref.empty()) 
    {
      pri(ref.back().first, ref.back().second, s);
      ref.pop_back();
    }
    printf("\n");
  } 
  return 0;
}

