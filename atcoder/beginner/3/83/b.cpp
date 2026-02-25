#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
int h, w, d;

int dr[] = {1, 0,0,-1};
int dc[] = {0, 1, -1, 0};

bool valid(int i, int j, int r, int c, int d) {
  int man = abs(i-r) + abs(j-c);
  if (man <=d ) {
    if (r >= 0 and r < h and
        c >= 0 and c < w)
      return true;
  }
  return false;
}

int v(vector<string>& grid, int i, int j, int d) {
  set<ii> s;
  int ans = 0;
  queue<ii> q;
  q.emplace(i,j);
  s.emplace(i,j);
  while (!q.empty()) {
    auto[r, c] = q.front(); q.pop();
    //cout << r << ' '<<c<<'\n';
    if (grid[r][c]=='.') 
    {
      ans++;
      grid[r][c]='x';
    }
    for (auto x = 0; x < 4; ++x) {
      int nr = r+dr[x];
      int nc = c+dc[x];
      if (valid(i,j,nr,nc,d) and s.find({ nr,nc }) == s.end()) {
        s.emplace(nr,nc);
        q.emplace(nr,nc);
      }
    }
  }
  return ans;
}

int f(vector<string>grid, int i, int j, int k, int l, int d) {
  int ans = v(grid, i, j, d);
  //cout << "-> "<<ans;
  ans += v(grid, k,l,d);
  //cout << "-> "<<ans<<'\n';
  return ans;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> h >> w >> d;
  vector<string> grid(h);
  for (auto i = 0; i < h; ++i) {
    cin >> grid[i];
  }
  int m = 0;
  //m = f(grid, 1,3,4,2,d);
  for (auto i = 0; i < h; ++i) {
    for (auto j = 0; j < w; ++j) {
      if (grid[i][j] == '.') {
        for (auto k = j+1; k < w; ++k) {
          if (grid[i][k]=='.')
            m = max ( m, f(grid, i, j, i, k, d) );
        }
        for (auto k = i+1; k < h; ++k) {
          for (auto l = 0; l < w; ++l) {
            if (grid[k][l]=='.')
              m = max ( m, f(grid, i, j, k, l, d) );
          }
        }
      }
    }
  }
  cout << m << '\n';
  return 0;
}


