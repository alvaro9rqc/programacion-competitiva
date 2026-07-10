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

using pl = pair<ll,ll>;
void solve() {
  int n,m;cin>>n>>m;
  vector<pl> val(n);
  for(auto& [x,y]: val) cin>>x>>y;
  sort(all(val),[&](pl& a, pl&b){
    return tuple{-a.first, a.second} < tuple{-b.first, b.second};
  });
  auto f=[&](ll d) {
    vl del(n+5), bes(n+5),cnt(n+5);
    ll p = 1;
    ll s=0;
    ll si=0;
    for(auto& [x,y]: val) {
      // dbg(x);
      if(y<p-d) continue;
      s+=x;
      ++si;
      del[y+1+d]+=x;
      cnt[y+1+d]++;
      if(del[p]) {
        s-=del[p];
        del[p]=0;
        si-=cnt[p];
        cnt[p]=0;
      }
      bes[p]=max(bes[p],s);
      if(p==si)++p;
    }
    for (auto i = 1; i < sz(bes); i++) 
      bes[i]=max(bes[i-1],bes[i]);
    return bes;
  };
  auto glo = f(1).back();
  auto que= f(0);
  // dbg(glo);
  for (auto _ = 0; _ < m; _++) {
    ll x, y;cin>>x>>y;
    cout<<max(glo, que[y]+x)<<' ';
  }
  cout<<'\n';
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

