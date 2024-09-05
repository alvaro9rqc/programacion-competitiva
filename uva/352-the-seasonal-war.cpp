#include <bits/stdc++.h> 
using namespace std;
int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

void floodfill(vector<string>& g, int r, int c) {
  if ( (r < 0) || (r >= g.size()) ) return; 
  if ( (c < 0) || (c >= g.size()) ) return;
  if (g[r][c] == '0') return;
  g[r][c] = '0';
  for (int i = 0; i < 8; ++i)
    floodfill(g, r+dr[i], c+dc[i]);
}

int main () {
  int cases = 0;
  int n ;
  while (cin >> n) {
    vector<string> g(n);
    cin>>ws;
    for (int i = 0; i < n; ++i) 
      getline(cin, g[i]);
    int cc = 0;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        if (g[i][j] == '1') {
          ++cc;
          floodfill(g, i, j);
        }
    cout << "Image number " << ++cases <<" contains " << cc<< " war eagles.\n";
    //cout << cc << '\n';
  }
}

