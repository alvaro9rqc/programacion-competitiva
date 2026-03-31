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
  while(tt--) {
    int n;cin>>n;
    vl mex(n);
    vl val(n);
    for(auto& i: val) cin >> i;
    set<ll> ost;
    ll ve=0;
    auto ev=[&](ll x) {
      ost.emplace(x);
      while(ost.count(ve)) ++ve;
    };
    int idx = -1;
    for (auto i = 0; i < n; i++) 
      if(val[i]==0) {idx=i;break;}
    ll ans  = 0;
    for (auto i = n-1; i >= 0; i--) {
      if(val[i]!=0) {
        ev(val[i]);
        ++ans;
      } else if(idx==i) {
        ev(0);
      }
      mex[i]=ve;
    }
    ll m = 1e10;
    bool can = 1;
    for (auto i = 0; i < n-1 and val[i]!=0; i++) {
      if(val[i]!=0) {
        m=min(m,val[i]);
        if(m<mex[i+1]) {can=0;break;}
      }
    }
    can&=(idx!=-1); 
    cout<<ans+can<<'\n';
  }
}

