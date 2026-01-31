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

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt; cin >> tt;
  while(tt--) {
    int n, cori;cin>>n>>cori;
    vector<string>gri(n);
    for(auto& i: gri) cin>>i;
    vector<vi> lr(n);
    for (auto i = 0; i < n; i++) {
      for (auto j = 0; j < n; j++) 
        if(gri[j][i]=='#')
          lr[i].emplace_back(j);
    }
    //dbg(lr[0].back());
    queue<ii> que;
    que.emplace(n-1, cori-1);
    auto isv = [&n](int r, int c) {
      return (0<= r and r < n and 0<= c and c < n);
    };
    int dc[] = {-1,0,1};
    while(sz(que)) {
      auto [r,c] = que.front(); que.pop();
      for(auto& xd: dc) {
        int nr = r-1;
        int nc = c+xd;
        if (isv(nr,nc) and gri[nr][nc]!='x' and gri[nr][nc]!='y') {
          auto& cell = gri[nr][nc];
          if (cell=='#') {
            if (sz(lr[nc]) and lr[nc].back()==nr) {
              lr[nc].pop_back();
              que.emplace(nr,nc);
              cell='x';
            } else {
              cell='y';
            }
          } else if (cell == '.') {
            cell='x';
            que.emplace(nr,nc);
          }
        }
      }
    }
    for(auto& i: gri[0]) 
    if (i=='x')cout <<1;
    else cout <<0;
    cout<<'\n';
  }
}

