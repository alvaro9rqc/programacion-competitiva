#include <bits/stdc++.h> 
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int dr[] = {1,1,1,-1,-1,-1,0,0};
int dc[] = {-1,0,1,-1,0,1,-1,1};

int flood (vector<string>& g, int r, int c) {
  if ( (r < 0) || (r >= g.size()) ) return 0;
  if ( (c < 0) || (c >= g.front().size()) ) return 0;
  if (g[r][c] == '0') return 0;
  int cc = 1;
  g[r][c] = '0';
  for (int i = 0; i < 8; ++i) 
    cc += flood(g, r+dr[i], c+dc[i]);
  return cc;
}
int main () {
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  cin >> ws;
  while (t--) {
    vector<string> g;
    while (true) {
      string s; getline(cin, s);
      //cout << s << '\n';
      if (s.size() == 0) break;
      g.push_back(s);
    }
    int n = 0;
    for (int i = 0; i < g.size();++i) 
      for (int j = 0; j < g.front().size();++j)
        if (g[i][j] == '1') {
          int c = flood(g, i, j);
          if (c > n) n = c;
        }
    cout << n << "\n";
    if ( t) cout << '\n';
    //cout << g.back() << '\n';
  }
  return 0;
}


