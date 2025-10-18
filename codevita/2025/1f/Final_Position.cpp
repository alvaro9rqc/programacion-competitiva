#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
#define dbg(x) cerr << #x << " = " << (x) << endl;
#define raya cerr << " ==================== " << endl;
#define rep(i, a, b) for (auto i = a; i < (b); ++i)
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)

vector<string> fun {
  "rRRwLbrw",
  "RRRRwwRw",
  "RRaawwaw",
  "wRalLLlw",
  "LwwLLLLw",
  "bwwLLbbw",
};


map<char,int> idx;
int lim = 52;
inline bool val(int x, int y) {
  return 0<=x and x <lim and 0<=y and y < lim;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  idx['r']=0;
  idx['R']=1;
  idx['a']=2;
  idx['l']=3;
  idx['L']=4;
  idx['b']=5;
  idx['d']=6;
  idx['w']=7;
  int n; cin >> n;
  vector<vector<char>> gri(52, vector<char>(52, 'd'));
  for (auto i = 0; i < n; i++) {
    int bx,by,ex,ey; cin >> bx >> by >> ex >> ey;
    if (by < ey) swap(bx,ex), swap(ey, by);
    if (bx < ex) {
      //right: R
      //begin
      int des = idx[gri[bx][by]];
      int nue = idx['r'];
      gri[bx][by] = fun[nue][des];
      for (auto x = bx+1,y=by-1; val(x,y) and x < ex; x++, --y){
        auto &c = gri[x][y];
        if (c >= (int)fun[0].size()) continue;
        c = fun[idx['R']][idx[c]];
      }
      gri[ex][ey] = fun[idx['a']][idx[gri[ex][ey]]];
    } else {
      // left:
      gri[bx][by] = fun[idx['l']][idx[gri[bx][by]]];
      for (auto x = bx-1,y=by-1; val(x,y) and x > ex; x--, --y){
        auto &c = gri[x][y];
        if (c >= (int)fun[0].size()) continue;
        c = fun[idx['L']][idx[c]];
      }
      gri[ex][ey] = fun[idx['b']][idx[gri[ex][ey]]];
    }
  }
  //for(auto& c: gri.front()) c = 'X';
  int x, y; cin >> x >> y;
  vector delx = {1,1,0,-1,-1,0,0,0};

  //for(auto& l: gri) {
  //  for(auto& c: l) cout << c <<' ';
  //  cout << '\n';
  //}

  while(y > 0 and gri[x][y]!='w') {
    if (not val(x,y))break;
    if (x >= lim) x = lim-1;
    char pos = gri[x][y];
    x+=delx[idx[pos]];
    y--;
  }
  cout << x << ' ' << y <<'\n';
}

