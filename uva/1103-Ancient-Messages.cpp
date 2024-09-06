#include <bits/stdc++.h> 
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int gold = 0;

int dr[] = {-1,0,0,1};
int dc[] = {0,1,-1,0};

void flood(vector<string>& g, int r, int c) {
  if (g[r][c] == 'G') ++gold;
  if (g[r][c] == '#') return;
  g[r][c] = '#';
  bool t = false;
  for (int i = 0; i < 4; ++i) 
    if (g[r+dr[i]][c+dc[i]] == 'T') {
      t = true; break;
    }
  if (! t) 
    for (int i = 0; i < 4; ++i) 
      if (g[r+dr[i]][c+dc[i]] == '.' || g[r+dr[i]][c+dc[i]] == 'G') 
        flood(g, r+dr[i], c+dc[i]);

}

int main () {
  ios_base::sync_with_stdio(false);
  int W, H;
  while (cin >> W >> H>>ws) {
    //cout << W << ' '<<H<<'\n';
    gold = 0;
    vector<string> g(H);
    for (int i = 0; i < H; ++i) getline(cin , g[i]);
    for (int i = 0; i < H; i++)
      for (int j = 0; j < W; ++j)
        if (g[i][j] == 'P')
        {
          flood(g, i, j);
          break;
        }
    cout << gold << '\n';
  }
  return 0;
}


