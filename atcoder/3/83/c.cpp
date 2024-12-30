#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vector<string> grid;
int h,w,d;

int dr[] = {-1,0,0,1};
int dc[] = {0,1,-1,0};

bool reach(int r,int c, int e) {
  if (e > d) return false;
  return 0 <= r and r < h and 
    0 <= c and c < w and 
    ( grid[r][c] == '.' or grid[r][c]=='x' );
}

int v(int i, int j) {
  int ans = 1;
  queue<tuple<int,int,int>> q;
  q.emplace(i,j,0);
  while (!q.empty()) {
    auto[r,c,e] = q.front(); q.pop();
    for (auto i = 0; i < 4; ++i) {
      int nr = r + dr[i];
      int nc = c + dc[i];
      if (reach(nr,nc,e+1)) {
        q.emplace(nr,nc,e+1);
        if (grid[nr][nc] == '.')
        {
          ans++;
          grid[nr][nc] = 'x';
        }
      }
    }
  }
  return ans;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> h >> w >> d;
  grid.resize(h);
  for (auto i = 0; i < h; ++i) {
    cin >> grid[i];
  }
  int ans = 0;
  for (auto i = 0; i < h; ++i) {
    for (auto j = 0; j < w; ++j) {
      if (grid[i][j] == 'H') 
        ans += v(i,j);
    }
  }
  cout << ans << '\n';
  return 0;
}


