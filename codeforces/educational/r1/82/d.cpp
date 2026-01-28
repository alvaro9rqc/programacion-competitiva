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
  const int lim = 200001;
  int tt;cin >> tt;
  while(tt--) {
    ll y;
    int n ; cin >>n>>y;
    vi ps(lim);
    int ma=0;
    for (auto i = 0; i < n; i++) {
      int x; cin >> x;
      ++ps[x];
      ma=max(ma,x);
    }
    for (auto i = 1; i < lim; i++) 
      ps[i]+=ps[i-1];
    ll ans = -1e16;
    for (auto k = 2; k < ma+2; k++) {
      ll lans = 0;
      for (auto i = 0; i*k < lim; i++) {
        int r = min(lim-1,(i+1)*k);
        int l = (i)*k;
        int p = ps[r]-ps[l];
        ll d =1ll*p*(i+1)-1ll*max(p-ps[i+1]+ps[i],0)*y; 
        //if (d){
        //  dbg(i);
        //  dbg(d);
        //  dbg(ps[i+1]-ps[i]);
        //  dbg(p);
        //  raya;
        //}
        lans+=d;
      }
      if (lans==529) {
        dbg(k);
      }
      ans=max(ans,lans);
    }
    cout << ans <<'\n';
  }
}

