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

const ll con=2,nco=1;

vector<vl> mtx;
ll m, a,b;

void dfs(ll x, ll y) {
  ll z = a*y+b*x;z%=m;
  if (z==0 or x==0 or y==0) {
    mtx[x][y]=con;
    return;
  }
  if (not mtx[y][z]) {
    mtx[x][y]=nco;
    dfs(y,z);
    if(mtx[y][z]==con) mtx[x][y]=con;
  } else if (mtx[y][z]==nco) {
    mtx[x][y]=nco;
  } else mtx[x][y]=con;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  cin>>m>>a>>b;
  mtx.assign(m,vl(m,0));
  ll ans = 0;
  for (auto x = 0; x < m; x++) {
    for (auto y = 0; y < m; y++) {
      if (mtx[x][y]==0){
        dfs(x,y);
      }
      // dbg(x);
      // dbg(y);
      // dbg(mtx[x][y]);
      // raya;
      ans+=(mtx[x][y]==nco);
    }
  }
  cout<<ans<<'\n';
}

