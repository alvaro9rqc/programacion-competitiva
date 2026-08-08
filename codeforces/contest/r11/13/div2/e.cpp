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
  ll n,m,d;cin>>n>>m>>d;
  map<ll,ll> omp;
  vl prr(m), rrr(m);
  for (ll i = 0,l=0; i < m; i++) {
    ll k,v;cin>>k>>v;
    prr[i]=k;
    rrr[i]=v+d;
    l=omp[k]= v+l;
  }
  // for(auto& [k,v]: omp) {
  //   cout<<k<<' '<<v<<'\n';
  // }
  // cout<<'\n';
  auto pts= [&](ll v) {
    ll r = v / n;
    v%=n;
    auto it = omp.upper_bound(v);
    auto ans = (it==omp.begin()?0:(--it)->second);
    return ans + v*d + r*((--omp.end())->second + n*d);
  };
  bool can = 0;
  for (auto i = 0; i < m and not can; i++) {
    ll ini = prr[i];
    ll xd = pts(ini-1);
    // dbg(ini);
    for(auto& [k,v]: omp) {
      // dbg(k);
      // dbg(pts(k+ini));
      dbg(v + xd + k*d);
      can = (v + xd + k*d > pts(k+ini));
      if(can)break;
    }
    raya;
  }
  cout<<(can?"yes":"no")<<'\n';
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

