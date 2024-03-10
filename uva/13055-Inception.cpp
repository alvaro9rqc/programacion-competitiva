#include <bits/stdc++.h> 
using namespace std;
int main () {
  string line;
  stack<string> people;
  int n; scanf("%d\n", &n);
  for (int i = 0; i < n; i++) {
    getline(cin, line);
    switch (line[0]) {
      case 'S':
        people.push(line.substr(6));
        break;
      case 'T':
        if (!people.empty())
          cout << people.top() << '\n';
        else printf("Not in a dream\n");
        break;
      //case 'K':
      default:
        if (!people.empty())
          people.pop();
        break;
    }
  }
  return 0;
}

