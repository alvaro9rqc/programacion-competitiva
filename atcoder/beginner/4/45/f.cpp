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
  ll n,k;cin>>n>>k;
  using vvvl = vector<vector<vl>>;
  vvvl bj(
    n,vector<vl>(
      n, vl()));
  for (auto i = 0; i < n; i++) {
    for (auto j = 0; j < n; j++) {
      ll c;cin>>c;
      bj[i][j].emplace_back(c);
    }
  }   
  ll inf= ll(1e18*3);
  for (auto lev = 1; (1ll<<lev)<=k; lev++) {
    for (auto i = 0; i < n; i++) {
      for (auto j = 0; j < n; j++) {
        auto& v=bj[i][j].emplace_back(inf);
        for (auto m = 0; m < n; m++) 
          v=min(
            v,
            bj[i][m][lev-1]+bj[m][j][lev-1]
          );
      }
    }
  }
  //ans
  for (auto i = 0; i < n; i++) {
    vl dis;
    for (auto l = 0; (1ll<<l) <= k; l++) {
      if(not(1ll<<l&k))continue;
      if(sz(dis)) {
        vl nex(n,inf);
        for (auto u = 0; u < n; u++) {
          auto& r = nex[u];
          for (auto v = 0; v < n; v++) 
            r=min(
              r,
              bj[u][v][l]+dis[v]
            );
        }
        swap(dis,nex);
      } else {
        dis.resize(n);
        for (auto j = 0; j < n; j++) dis[j]=bj[j][i][l];
      }
    }
    cout<<dis[i]<<'\n';
  }
}

