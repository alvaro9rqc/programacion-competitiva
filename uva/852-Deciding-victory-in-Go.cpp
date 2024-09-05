#include <bits/stdc++.h> 
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

char check;
char dr[] = {1,-1,0,0};
char dc[] = {0,0,1,-1};

int flood(vector<string>& g, int r, int c) {
  if ( (r < 0) || (r >= 9) ) return 0;
  if ( (c < 0) || (c >= 9) ) return 0;
  if ( g[r][c] == 'O' || g[r][c] == 'X' ) 
  {
    if (check == 's') check = g[r][c];
    else if(check != g[r][c]) check = 'f';
  }
  if (g[r][c] == '.') {
    int sg = 1;
    g[r][c] = 'e';
    for (int i = 0; i < 4; ++i) 
      sg += flood(g, r+dr[i], c+dc[i]);
    return sg;
  }
  return 0;
}

int main () {
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t>>ws;
  while(t--) {
    vector<string> g(9);
    int no, nx;
    no=nx=0;
    check = 's';
    for (int i = 0; i < 9; ++i) getline(cin, g[i]);
    for (int i = 0; i< 9; ++i)
      for (int j = 0; j < 9 ; ++j)
        if (g[i][j] == 'O') ++no;
        else if (g[i][j] == 'X') ++nx;
        else if (g[i][j] == '.') {
          int sg = flood(g, i, j);
          //cout << "->" << sg <<": " << i <<' '<<j <<' '<<g[i]<<  '\n';
          if (check == 'X') nx += sg;
          else if (check == 'O') no += sg;
          check = 's';
        }
    cout << "Black "<<nx<<" White "<<no<<'\n';
  }
  return 0;
}


