#include <bits/stdc++.h> 
using namespace std;
int main () {
  char dumy;
  int n;
  while (true) {
    //scan the elements
    vector <int> line;
    string dummy; 
    if (!getline(cin, dummy)) break;
    istringstream ss(dummy); int help;
    while (ss >> help) 
      line.push_back(help);
    stack <pair<int, int>> st;
    bool f = true;
    //operations
    for (int i = 0; i < line.size(); i++) {
      if (st.empty() && line[i] < 0) st.push({line[i], 0});
      else if (!st.empty() && st.top().first == -line[i]) {
        st.pop();
        if (!st.empty()) {
          st.top().second -= line[i];
          if (st.top().second <= st.top().first) {
            f = false;
            break;
          }
        }
      } else if (!st.empty() && line[i] < 0) {
        st.push({line[i], 0});
      } else {
        f = false;
        break;
      }
    }
    if (f && st.empty()) cout << ":-) Matrioshka!\n";
    else cout << ":-( Try again.\n"; 
  }
  return 0;
}
