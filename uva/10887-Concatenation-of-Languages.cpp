#include <bits/stdc++.h> 
using namespace std;
int main () {
  int t; scanf("%d", &t);
  int k = t;
  while (t--) {
    int m, n; scanf("%d %d", &m, &n);
    //scanf("\n");
    string c; getline(cin, c);
    vector<string> l1(m);
    vector<string> l2(n);
    for (int i = 0; i < m; i++) {
      getline(cin, l1[i]);
    }
    for (int i = 0; i < n; i++) {
      getline(cin, l2[i]);
    }
    unordered_set<string> lang;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        lang.insert(l1[i] + l2[j]); 
      }
    }
    printf("Case %d: %ld\n", k - t, lang.size());
  }
  return 0;
}

