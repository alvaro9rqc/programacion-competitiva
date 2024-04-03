#include <bits/stdc++.h> 
using namespace std;
int main () {
  char dumy;
  int n;
  while (true) {
    //scan the elements
    vector <int> line;
    if (scanf("%d%c", &n, &dumy) == EOF ) break;
    line.push_back(n);
    while (scanf("%d%c", &n, &dumy)) {
      line.push_back(n);
      if (dumy == '\n') break;
    }
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
    if (f) cout << ":-) Matrioshka!\n";
    else cout << ":-( Try again.\n"; 
  }
  return 0;
}

