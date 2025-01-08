#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int H,W,D;

int dr[] = {1,-1,0,0};
int dc[] = {0,0,-1,1};

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> H>>W>>D;
  vector<string> g(H);
  for(auto& i: g) {
    cin >> i;
  }
  queue<tuple<int,int,int>> qu;
  ll ans = 0;
  for (auto i = 0; i < H; ++i) {
    for (auto j = 0; j < W; ++j) {
      if (g[i][j] == 'H'){
        ++ans;
        qu.emplace(i,j,D-1);
        g[i][j] = 'x';
      }
    }
  }
  if (D == 0) {
    cout << ans << '\n';
    return 0;
  }
  while(!qu.empty()) {
    auto [r, c, d] = qu.front(); qu.pop();
    for (auto i = 0; i < 4; ++i) {
      int nr=r+dr[i], nc=c+dc[i];
      if (0 <= nr and nr < H and 0<=nc and nc < W and g[nr][nc]=='.') {
        g[nr][nc] = 'x';
        if (d>0)
          qu.emplace(nr,nc,d-1);
        ++ans;
      }
    }
  }
  cout << ans << '\n';
  return 0;
}


