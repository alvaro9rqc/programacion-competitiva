#include <bits/stdc++.h> 
using namespace std;
int main () {
  int t; scanf("%d", &t); 
  while (t--) {
    int m, n; scanf("%d %d\n", &m, &n);
    vector < unordered_map <char, int> >maps (n, { 
        {'A', 0},
        {'T', 0},
        {'G', 0},
        {'C', 0}
        }); 
    string line;
    string ans(n, 'A');
    for (int i = 0; i < m; i++) {
      getline(cin, line);
      for (int j = 0; j < n; j++) {
        maps[j][line[j]]++;
        if ( maps[j][line[j]] >= maps[j][ ans[j] ] ) {
          if (  maps[j][line[j]] == maps[j][ ans[j] ]  ) {
            if (line[j] < ans[j]) ans[j] = line[j];
          } else {
            ans[j] = line[j];
          }
        }
      }
    }
    int cons = 0;
    for (int i = 0; i < n; i++) {
      cons += m - maps[i][ans[i]];
    }
    printf("%s\n%d\n", ans.c_str(), cons);

  }
  return 0;
}

