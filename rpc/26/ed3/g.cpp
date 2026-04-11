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
  ll  p, q;cin>>p>>q;
  ll k = 2*(q-p);
  long double one=1;
  bool can = 0;
  ll rf=0, gf=0;
  // for (auto r = ll(1e6); r < ll(1e6)+1 and not can; r++) {
  for (auto r = 1ll; r < ll(1e6)+1 and not can; r++) {
    ll lef=r, rig=1e6;
    long double f = 0;
    ll g=-10;
    while(lef<rig) {
      ll m = (rig+lef)/2;
      f = (r-one)*p/m + (m-one)/r*p;
      // dbg(rig);
      // dbg(lef);
      // dbg(f-k);
      // dbg(m);
      // if(-one <= (k-f) and (k-f)<= one) {g=m;break;}
      if(k==f) {g=m;break;}
      if (f>k) rig=m-1;
      else lef=m+1;
      g=m;
    }
    // dbg(g);
    // dbg(k);
    for (auto i = max(1ll,g-3); i < g+3; i++) {
      auto nu = 2*r*i;
      auto de = (r+i)*(r+i-1);
      auto gd = gcd(nu,de);
      nu/=gd;
      de/=gd;
      if(nu==p and de == q) {
        can=1;rf=r;gf=i;
      }
    }
  }
  if(can) {
    cout<<rf<<' '<<gf<<'\n';
  } else {
    cout<<"impossible\n";
  }
}

