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
  using terr = map<ll,pair<ll,ll>>;
  while(tt--) {
    ll n, hei;cin>>n>>hei;
    vl h(n); for(auto& i: h) cin >> i;
    vector<terr> tr(n),tl(n);
    for (auto i = 0; i < n; i++) {
      //left
      ll nh=0, acc=0;
      for (auto j = i; j >= 0; j--) {
        if(h[j]>nh)nh=h[j];
        acc+=nh;
        tl[i][nh] = {j,acc};
      }
      if (nh != hei) tl[i][hei]={-2,-2};
      acc=0,nh=0;
      for (auto j = i; j < n; j++) {
        if(h[j]>nh)nh=h[j];
        acc+=nh;
        tr[i][nh] = {j,acc};
      }
      if (nh != hei) tr[i][hei]={-2,-2};
    }
    //sol
    ll ans = 0;
    for (auto i = 0; i < n; i++) {
      vl arr(n);
      for (auto j = i; j < n; j++) arr[j]=(j==i)?h[i]:max(h[j],arr[j-1]);
      for (auto j = i; j >= 0; j--) arr[j]=(j==i)?h[i]:max(h[j],arr[j+1]);
      ll lans = 0;
        // dbg(i);
      for (auto j = i+1; j < n; j++) {
        if(h[j]==arr[j]) continue;
        // dbg(arr[j]);
        // dbg(h[j]);
        // dbg(j);
        auto [le, tle] = (--tl[j].lower_bound(arr[j]))->second;
        auto [ri, tri] = (--tr[j].lower_bound(arr[j]))->second;
        // dbg(le);
        // dbg(tle);
        // dbg(ri);
        // dbg(tri);
        lans=max(lans, arr[j]*(ri-le+1) - tle-tri + h[j]);
        // dbg(lans);
      }
      for(auto& j: arr) lans+=hei-j;
      ans=max(ans,lans);
    }
    cout<<ans<<'\n';
    // raya;
  }
}

