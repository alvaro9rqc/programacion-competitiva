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

ll mod = 998244353;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt;cin>>tt;
  ll lim = 2e5+10;
  vl fac(lim,1);
  for (auto i = 1ll; i < lim; i++) 
    fac[i]*=fac[i-1]*i,fac[i]%=mod;
  auto inv=[&](ll b) {
    ll e = mod-2;
    ll r=1;
    while(e) {
      if(e&1) r*=b,r%=mod;
      b*=b;b%=mod;
      e>>=1;
    }
    return r;
  };
  auto C=[&](ll a, ll b) {
    return (fac[a]*inv(fac[b]))%mod*inv(fac[a-b])%mod;
  };
  while(tt--) {
    int n;cin>>n;
    ll s = 0;
    vl val(n); for(auto& i: val) cin >> i,s+=i;  
    bool can = (s==n);
    for (auto i = 0; i < n/2; i++) can&=(val[n-1-i]==0);
    for (auto i = 0ll,p=0ll; i < n/2; i++) {
      p+=val[i];
      can&=(p>=2*(i+1));
    }
    if(not can) {cout<<0<<'\n';continue;}
    ll esp=1+!(n&1);
    ll ans = 1;
    for (auto i = (n-1)/2; i >= 0; i--) {
      ans*=C(esp,val[i]);ans%=mod;
      esp-=val[i];
      esp+=2;
    }
    cout<<ans<<'\n';
  }
}

