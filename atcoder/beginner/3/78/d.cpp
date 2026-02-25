#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int H,W,K;
int dr[] = {1,-1,0,0};
int dc[] = {0, 0,-1,1};

ll dfs (vector<string>& g, int r, int c, int e) {
  if (e == 0)return 1;
  g[r][c] = '#';
  ll ans = 0;
  for (auto i = 0; i < 4; ++i) {
    int nr=r+dr[i], nc=c+dc[i];
    if (
        0 <= nr and nr < H and
        0 <= nc and nc < W and
        g[nr][nc] == '.'
       )
      ans += dfs(g,nr, nc, e-1);
  }
  g[r][c] = '.';
  return ans;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> H >> W >> K;
  vector<string> g(H);
  for(auto& i: g) {
    cin >> i;
  }
  ll ans = 0;
  for (auto i = 0; i < H; ++i) {
    for (auto j = 0; j < W; ++j) {
      if (g[i][j] == '.') 
      {
        ans += dfs(g, i, j, K);
      }
    }
  }
  cout << ans << '\n';
  return 0;
}


