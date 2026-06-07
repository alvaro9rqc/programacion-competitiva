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

void solve() {
  ll n, k;cin>>n>>k;
  string sx,sy;
  cin>>sx>>sy;
  ll vx=0,vy=0,vz=0;
  for (auto i = 0; i < n; i++) {
    vx+=sx[i]=='1';
    vy+=sy[i]=='1';
    vz+=(sx[i]!=sy[i]);
  }
  vx*=(n-vx);
  vy*=(n-vy);
  vz*=(n-vz);
  vector<vl> v = {
    {1,1,0},
    {1,1,1}
  };
  ll xd=3;
  ll go=(1ll<<k)+1;
  while(xd!=go) {
    ll x,y,z;
    ll i = sz(v)-1;
    x=v[i][0]+2*v[i-1][0]-1;
    y=v[i][1]+2*v[i-1][1]-1;
    z=v[i][2]+2*v[i-1][2];
    xd=x+y+z;
    v.emplace_back(vl{x,y,z});
  }
  ll x=v.back()[0]*vx;
  ll y=v.back()[1]*vy;
  ll z=v.back()[2]*vz;
  cout<<x+y+z<<'\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt=1;
  cin>>tt;
  while(tt--) {
    solve();
  }
}

