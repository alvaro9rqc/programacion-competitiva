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
int h, w;

const int r=0,l=1,u=2,dow=3;
const int B = 0, C = 1;

int dir[][4] = {
  {dow,u,l,r},
  {u,dow,r,l}
};

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

using iii = tuple<int,int,int>;
iii nn(int d, int x, int y, char t) {
  int d2 = d;
  if (t != 'A') {
    int tt = (t=='C')?C:B;
    d2 = dir[tt][d];
  }
  x+=dx[d2];
  y+=dy[d2];
  return {d2, x, y};
}

iii na (int d, int x, int y, char t) {
  if (t == 'B') t = 'C';
  else if (t == 'C') t = 'B';
  return nn(d, x, y, t);
}

bool val(int x, int y) {
  return 0 <= x and x < h and 0 <= y and y < w;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt; cin >> tt;
  while(tt--) {
    cin >> h >> w;
    vector<string> gri(h);
    for(auto& i: gri) cin >> i;
    vector<vector<vector<bool>>> vis(4, vector<vector<bool>>(h, vector<bool>(w,0)));
    vector<vector<vector<bool>>> visn(4, vector<vector<bool>>(h, vector<bool>(w,0)));
    queue<iii> now, nex;
    now.emplace(r, 0,0);
    vis[r][0][0]=1;
    int cha = 0;
    char dt[] = {'A', 'B', 'C'};
    int ans = int(1e8);
    while(1) {
      while(now.size()) {
        auto[d,x,y]=now.front();
        vis[d][x][y]=1;
        now.pop();
        //dbg(d);
        //dbg(x);
        //dbg(y);
        if (x == h-1 and y == w-1) {
          auto[d2,x2,y2] = nn(d,x,y,gri[x][y]);
          if (y2 != w) ans=min(ans, cha+1);
          else ans=min(ans,cha);
        }
        auto[d2,x2,y2] = nn(d,x,y,gri[x][y]);
        //dbg(vis[d2][x2][y2]);
        if (val(x2,y2) and not vis[d2][x2][y2]) {
          vis[d2][x2][y2]=1;
          visn[d2][x2][y2]=1;
          now.emplace(d2,x2,y2);
        }
        for(auto& i: dt) {
          if (i == gri[x][y]) continue;
          auto[d3,x3,y3] = nn(d,x,y,i);
          if (val(x3,y3) and not visn[d3][x3][y3] and not vis[d3][x3][y3]) {
            visn[d3][x3][y3]=1;
            nex.emplace(d3,x3,y3);
          }
        }
      }
      swap(now,nex);
      if (now.empty()) {break;}
      ++cha;
      //raya;
    }
    cout << ans <<'\n';
  }
}

