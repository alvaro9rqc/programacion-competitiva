#include <bits/stdc++.h> 
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
int dr[] = { -1, 0, 0, 1 };
int dc[] = { 0, 1, -1, 0 };
char land;
char diff;
int flood (vector<string>& g, int r, int c) {
  if (c == g[0].size()) c = 0;
  if (c == -1) c = g[0].size()-1;
  if ( (r < 0) || (r >= g.size()) ) return 0;
  if (g[r][c] != land) return 0;
  g[r][c] = diff;
  int cc = 1;
  for (int i = 0; i < 4; ++i) 
    cc += flood(g, r+dr[i], c+dc[i]);
  return cc;
}

int main () {
  ios_base::sync_with_stdio(false);
  int m, n;
  while (cin >> m >> n) {
    cin >> ws;
    vector<string> g(m);
    for (int i = 0; i < m; ++i) getline(cin, g[i]);
    int x, y; cin >> x >> y;
    land = g[x][y];
    diff = (land == '.')? 'x':'.';
    flood (g, x, y);
    int cc = 0;
    for (int i = 0; i < g.size(); ++i) 
      for (int j = 0; j < g.front().size(); ++j)
        if (g[i][j] == land) 
        {
          int d = flood(g, i, j);
          if (d > cc ) cc = d;
        }
    cout << cc << '\n';
  }
  return 0;
}


