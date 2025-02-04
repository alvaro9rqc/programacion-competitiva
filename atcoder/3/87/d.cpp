#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;

typedef pair<ll, ll> ll_p; 
typedef tuple<ll, ll, ll> ll_t; 
typedef vector<ll> vll;
typedef vector<ll_p> vll_p;   
typedef vector<ll_t> vll_t;

int W, H;

vector<string> m;

vector<string> g;
int gr=-1,gc,sr,sc=-1;

bool isfree(char d, char nd, int r, int c) {
  if (0 <= r and r < H and
      0 <= c and c < W ) {
    if (m[r][c] == '.' || m[r][c] == 'G') {
      //cout << r <<' '<<c<<'\n';
      m[r][c] = nd;
      return true;
    } else if (m[r][c] == d) {
      m[r][c] = '#';
      return true;
    }
  }
  return false;
}

int f(char d) {
  m = g;
  queue<tuple<char,int,int>> q;
  //cout << d <<'\n';
  q.emplace( d,sr,sc );
  m[sr][sc] = d; 
  int lev=1,lay=1;
  while(not q.empty()) {
    int tmp = lay;
    lay = 0;
    for (int i = 0; i < tmp; ++i){
      auto [d,r,c] = q.front();q.pop();
      //cout << d << ' ' << r << ' ' << c <<'\n';
      int dr=0, dc=0;
      if (d == 'r') dc = 1;
      else dr = 1;
      char nd = d =='r'? 'c':'r';
      for (auto i = 0; i < 2; ++i) {
        if (isfree(d, nd,r+dr,c+dc)) {
          lay++;
          q.emplace(nd,r+dr,c+dc);
          if (r+dr == gr and c+dc == gc)
            return lev;
        }
        dr *= -1;
        dc *= -1;
      }
    }
    //cout << "-> " << q.size() << '\n';
    ++lev;
  }
  //cout << '\n';
  //for(auto& s: m) {
  //  cout << s << '\n';
  //}
  return -1;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> H >> W;
  g.resize(H);
  for (auto i = 0; i < H; ++i) {
    cin >> g[i];
    if (gr == -1 or sc == -1) 
      for (auto j = 0; j < W; ++j) {
        if ( g[i][j] == 'S' ) {
          sr = i;
          sc = j;
        }
        if ( g[i][j] == 'G' ) {
          gr = i;
          gc = j;
        }
      }
  }
  int a = f('c');
  int b = f('r');
  if (a != -1 and b != -1) cout << min(a,b) <<'\n';
  else cout << max(a,b)<<'\n';
  //cout << g[0]<<'\n';

  return 0;
}


