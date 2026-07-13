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

ll mod = 1e9+7;

ll fe(ll e) {
  ll b = 2;
  ll r = 1;
  while(e) {
    if(e&1) r*=b,r%=mod;
    b*=b,b%=mod;
    e>>=1;
  }
  return r;
}

ll fr(ll x,ll  r) {return (x-(r%mod)+mod)%mod;}
ll fc(ll x) {return x>0?fe(x-1):1;}

void solve() {
  ll n;cin>>n;
  ll he = 0;
  vl val;
  vl cnt;
  for (auto i = 0; i < n; i++) {
    ll x;cin>>x;
    if(x==-1)++he;
    else {
      if(sz(val) and val.back()==x)
        ++cnt.back();
      else val.emplace_back(x),cnt.emplace_back(1);
    }
  }
  ll cm0 = he?fe(he-1):1;
  ll cm1 = he?fe(he-1):0;
  // if(he and not sz(val)) {
  //   cout<<cm0<<'\n';
  //   return;
  // } else if (!he) {
  //   cm0=1;cm1=0;
  // }
  ll t0=1;
  ll t1=0;
  for (auto i = sz(val)-1; i >= 0; i--) {
    //particular
    // if(val[i]==1){
    //   // t1=cnt[i]*t0%mod;
    //   t1+=cnt[i]*fc(cnt[i]-1)%mod*t0%mod;
    //   t1%=mod;
    // }
    if(i and val[i-1]+1==val[i]) {
      ++t1;
    }
    if(cnt[i]>1) {
      t0= (fe(cnt[i]-1)*(t0))%mod;
    }
  }
  ll ans = t0*cm0%mod;
  ans += cm1*t1%mod*t0%mod;
  ans %=mod;
  cout<<(ans)<<'\n';
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

