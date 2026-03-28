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
  int tt;cin>>tt;
  vl aux(2e5+10);
  ll mod = 676767677; 
  aux[0]=1;
  aux[1]=1;
  ll xd = 2;
  for (auto i = 2; i < sz(aux); i++) {
    aux[i]=xd;
    xd+=xd;
    xd%=mod;
  }
  dbg(aux[4]);
  while(tt--) {
    ll x, y;cin>>x>>y;
    if(not(x) or not(y)) {
      cout<<aux[max(x,y)]<<'\n';
      for (auto i = 0; i < max(x,y); i++) cout<<(x?1:-1)<<' ';
      cout<<'\n';
    } else {
      ll ans = 0;
      ll ma = max(x,y)-min(x,y)-1;
      ll mi = 1;
      dbg(ma);
      dbg(mi);
      while(ma>=0){
        ans+=((ma--%mi++)==0);
      }
      if(ans==0)++ans;
      cout<<(ans)<<'\n';
      for (auto i = 0; i < x; i++) cout<<1<<' ';
      for (auto i = 0; i < y; i++) cout<< -1<<' ';
      cout<<'\n';
    }
  }
}

