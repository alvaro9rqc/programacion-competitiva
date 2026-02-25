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
  int n, m;
  cin >> n >> m;
  const ll inf = ll(1e16);
  vector<vl> mtx(n+1, vl(n+1,inf));
  for (auto i = 0; i < n+1; i++) 
    mtx[i][i]=0;
  for (auto i = 0; i < m; i++) {
    int a, b; ll c; cin >> a >> b >> c;
    --a,--b;
    mtx[a][b]=min(mtx[a][b], c);
    mtx[b][a]=min(mtx[b][a], c);
  }
  int sky = n;
  int K; ll t; cin >> K >> t;
  for (auto i = 0; i < K; i++) {
    int x; cin >> x;--x;
    mtx[x][sky]=t;
    mtx[sky][x]=0;
  }
  for (auto k = 0; k < n+1; k++) 
    for (auto j = 0; j < n+1; j++) 
      for (auto i = 0; i < n+1; i++) 
        mtx[i][j]=min(mtx[i][j], mtx[i][k]+mtx[k][j]);
  int q; cin >> q;
  for (auto _ = 0; _ < q; _++) {
    int ty; cin>>ty;
    if(ty==1) {
      int x, y; ll c; cin >> x >> y >> c;
      --x,--y;
      for (auto i = 0; i < n+1; i++) 
        for (auto j = 0; j < n+1; j++) 
          mtx[i][j]=min(mtx[i][j], mtx[i][x]+c+mtx[y][j]),
            mtx[i][j]=min(mtx[i][j], mtx[i][y]+c+mtx[x][j]);
    } else if (ty==2){
      int x; cin >>x;--x;
      for (auto i = 0; i < n+1; i++) 
        for (auto j = 0; j < n+1; j++) 
          mtx[i][j]=min(mtx[i][j], mtx[i][x]+t+mtx[sky][j]),
           mtx[i][j]=min(mtx[i][j], mtx[i][sky]+mtx[x][j]);
    } else {
      ll ans = 0;
      for (auto i = 0; i < n; i++) {
        for (auto j = 0; j < n; j++) 
          if (mtx[i][j]<inf){
            ans+=mtx[i][j];
            //dbg(i+1);
            //dbg(j+1);
            //dbg(mtx[i][j]);
          }
      }
      cout << ans <<'\n';
    }
  }
}

