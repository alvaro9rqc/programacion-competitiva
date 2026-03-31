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
  int n,time;cin>>n>>time;
  map<ii,vi> omp;
  for (auto i = 0; i < time; i++) {
    int m;cin>>m;
    int u,v;cin>>u>>v;
    --u,--v;
    omp[{u,i}].emplace_back(v);
    omp[{v,i}].emplace_back(u);
  }
  int kt;cin>>kt;
  vi tel(kt); for(auto& i: tel) cin >> i,--i;
  int ans = -1;
  queue<ii> que;
  set<ii> vis;
  que.emplace(0,0);
  vis.emplace(0,tel[0]);
  while(sz(que)) {
    auto [u,ti]=que.front();que.pop();
    if(u==n-1) {ans=ti+1;break;}
    if(ti==kt) break;
    for(auto& v: omp[{u,tel[ti]}]) {
      if(vis.count({v,tel[ti+1]})) continue;
      que.emplace(v,ti+1);
    }
  }
  cout<<ans<<'\n';
}
