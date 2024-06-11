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
  unordered_map<char, char> close = {
    {')', '(',},
    {']', '[',},
    {'>', '<',},
    {'}', '{' }
  };
  string line;
  while (getline(cin, line)) {
    //cout << line << '\n';
    stack <char> st;
    int n = 0;
    int lo = n;
    for (int i = 0; i < line.size(); i++) {
      ++n;
      if (open.find(line[i]) != open.end() ) {
        if (line[i] == '(' && i < line.size() - 1 && line[i + 1] == '*') {
          st.push('*');
          i++;
        } else 
          st.push(line[i]);
        lo = n;
      } else {
        if (close.find(line[i] ) != close.end()) {
          if (st.size() == 0) 
          {
            if (i > 0 && line[i] == ')' && line[i-1] == '*')
              cout << "NO " << n-1 << '\n';
            else 
              cout << "NO " << n << '\n';
            n = -1;
            break;
          }
          if (line[i] == ')' && i > 0 && line[i-1] == '*' ) {
            if (st.top() != '*' ){
              cout << "NO " << n-1 << '\n';
              n = -1;
              break;
            } 
            if(i > 1 && line[i-2] == '(')  {
              cout << "NO " << n << '\n';
              n = -1;
              break;
            }
            if (st.top() == '*'){
              n--;
              st.pop(); continue;
            }
          }
          if (close[line[i]] != st.top() ) {
            cout << "NO " << n << '\n';
            //cout << "i: " << i << " " <<  st.top() << " xd " << line[i] << '\n';
            n = -1;
            break;
          }
          st.pop();
        }
      }
    }
    if (n == -1) continue;
    if (st.size() != 0) {
      cout << "NO " << n + 1 << '\n';
    } else {
      cout << "YES" << '\n';
    }
  }
  return 0;
}

