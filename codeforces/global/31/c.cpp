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
    ll n,k;cin>>n>>k;
    vl ans(k);
    ll m=0;
    if(k&1){
      for(auto& i: ans) i=n;
    } else {
      ll lib=0;
      ll msb=0;
      for (auto i = 60; i >=0; i--) {if(1ll<<i&n){msb=i;break;}}
      for (auto i = msb; i >=0; i--) {
        if(1ll<<i&n) {
          ll lim = min(k-1,lib);
          for (auto j = 0; j < lim; j++) ans[j]|=1ll<<i;
          for (auto j = lim+1; j < k; j++) ans[j]|=1ll<<i;
          lib=min(lib+1,k);
        } else {
          ll lim = lib-(lib&1);
          for (auto j = 0; j < lim; j++) ans[j]|=1ll<<i;
        }
      }
    }
    for(auto& i: ans) cout<<i<<' ',(m^=i);
    cout<<'\n';
    // dbg(m);
  }
}

