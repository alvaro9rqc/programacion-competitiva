#include <bits/stdc++.h> 
using namespace std;
int main () {
  ios_base::sync_with_stdio(false);
  unordered_set<char> open = {
    '(',
    '[',
    '<',
    '{'
  };
  unordered_map<char, char> cloe = {
    {')', '(',},
    {']', '[',},
    {'>', '<',},
    {'}', '{' }
  };
  string line;
  while (getline(cin, line)) {
    cout << line << '\n';
  }
  return 0;
}

