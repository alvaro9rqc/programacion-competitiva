#include <bits/stdc++.h> 
using namespace std;
int main () {
  int t; scanf("%d", &t); 
  while (t--) {
    int m, n; scanf("%d %d\n", &m, &n);
    vector < string > v(m);
    vector < unordered_map <char, int> >maps (n, { 
        {'A', 0},
        {'T', 0},
        {'G', 0},
        {'C', 0}
        }); 
    //maps.assign(n, unordered_map<char, int>() );
    vector <int> rep(n, 0);
    for (int i = 0; i < m; i++) {
      getline(cin, v[i]);
      for (int j = 0; j < n; j++) {
        maps[j][v[i][j]]
        if ()
      }
    }
    //cout << v[m - 1] << '\n'; -- all correct

  }
  return 0;
}

