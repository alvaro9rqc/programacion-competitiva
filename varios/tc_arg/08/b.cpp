#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
#define endl '\n'
#define dbg(x) cerr << #x << " = " << (x) << endl;
#define raya cerr << " ==================== " << endl;
#define FOR(i, a, b) for (auto i = a; i < (b); ++i)
#define sz(x) (int)(x).size()

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  vector<vl> m = {
    {1,1, 1, 1},
    {1,1, 1, 1},
    {1,1, 1, 1},
    {1,1, 1, 1},
  }; 
  string s; cin >> s;
  auto f = [&]() {
    int x[] = {0,0,0,0};
    int y[] = {0,0,0,0};
    for (auto i = 0; i < 4; ++i) {
      int on = 1;
      for (auto j = 0; j < 4; ++j) {
        if (m[i][j]) { on = 0; break; };
      }
      if (on) y[i]=1;
    }
    for (auto i = 0; i < 4; ++i) {
      int on = 1;
      for (auto j = 0; j < 4; ++j) {
        if (m[j][i]) { on = 0; break; };
      }
      if (on) x[i]=1;
    }
    for (auto i = 0; i < 4; ++i) {
      if (x[i]) for (auto j = 0; j < 4; ++j) {
        m[j][i]=1;
      }
      if (y[i]) for (auto j = 0; j < 4; ++j) {
        m[i][j] = 1;
      }
    }
  };
  auto mhor = [&](int r, int c) {
    if (m[r][c] and m[r][c+1]) {
      m[r][c] = m[r][c+1]=0;
      cout << r+1 << " " << c+1<<'\n';
      return true;
    }
    return false;
  };
  auto mver = [&] (int r, int c) {
    if (m[r][c] and m[r+1][c]) {
      m[r][c] = m[r+1][c] = 0;
      cout << r+1 << " " << c+1<<'\n';
      return true;
    }
    return false;
  };
  int rver[] = {0,0,0,0,2,2,2,2};
  int cver[] = {0,1,2,3,0,1,2,3};
  int rhor[] = {0,1,0,1,2,3,2,3};
  int chor[] = {0,0,2,2,0,0,2,2};
  int idx = 0;
  for(auto& b: s) {
    idx = ++idx%8;
    //ver
    if (b == '0') {
      bool fg = false;
      for (auto i = 0; i < 8; ++i) {
        if (fg = mver( rver[(idx+i)%8], cver[(idx+i)%8] )) break;
      }
      for (auto i = 0; i < 4; ++i) {
        for (auto j = 0; j < 4; ++j) {
          cout << m[i][j] << (j == 3? '\n':' ');
        }
      }
      if (not fg) 
      {
        cout << "gaaaaaaaa\n";
      }
    } else {
      bool fg = false;
      for (auto i = 0; i < 8; ++i) {
        if (fg = mhor( rhor[(idx+i)%8], chor[(idx+i)%8] )) break;
      }
      for (auto i = 0; i < 4; ++i) {
        for (auto j = 0; j < 4; ++j) {
          cout << m[i][j] << (j == 3? '\n':' ');
        }
      }
      if (not fg) 
      {
        cout << "gaaaaaaaa hhhhhh\n";
      }
    }
    f();
  }
}


