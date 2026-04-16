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

struct FT {
  vector<ll> s;
  FT(int n) : s(n) {}
  void update(int pos, ll dif) { // a [pos] += dif
    for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
  }
  ll query(int pos) { // sum of values in [0 , pos)
    ll res = 0;
    for (; pos > 0; pos &= pos - 1) res += s[pos-1];
    return res;
  }
  int lower_bound(ll sum) {// min pos st sum of [0 , pos ] >= sum
    // Returns n if no sum is >= sum, or −1 if empty sum is
    if (sum <= 0) return -1;
    int pos = 0;
    for (int pw = 1 << 25; pw; pw >>= 1) {
      if (pos + pw <= sz(s) && s[pos + pw-1] < sum)
        pos += pw, sum -= s[pos-1];
    }
    return pos;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n,m;cin>>n>>m;
  int lim = int(2e5+3);
  vi fre(lim), trr(m);
  FT pre(lim);
  for (auto i = 0; i < n; i++) {
    int x;cin>>x;
    ++fre[x];
  }
  for(auto& i: trr) cin>>i;
  for (auto i = 0; i < lim; i++) 
    if(fre[i]) pre.update(i,fre[i]);
  vl fac(lim,1),ifac(lim,1);
  ll ans = 0;
  ll mod = 998244353;
  auto inv = [&](ll b){
    ll e= mod-2;
    ll r = 1;
    while(e) {
      if(e&1) r*=b,r%=mod;
      e>>=1;
      b*=b;b%=mod;
    }
    return r;
  };
  for (auto i = 1ll; i < lim; i++) {
    fac[i]=(fac[i-1]*i)%mod;
    ifac[i]=inv(fac[i]);
  }
  ll E = fac[n-1];
  for (auto i = 0; i < lim; i++) 
    if(fre[i]) E=(E*ifac[fre[i]])%mod;
  // dbg(E);
  ll aci=0;
  for (auto i = 0; i < min(n,m); i++) {
    auto r=pre.query(trr[i]); 
    ans+=E*r%mod;
    // dbg(E*r);
    ans%=mod;
    if(fre[trr[i]]) pre.update(trr[i],-1),++aci;
    else break;
    E*=inv( n-i-1 )*fre[trr[i]]--%mod;
    E%=mod;
  }
  if(n<m and aci==n) ans+=1,ans%=mod;
  if (n>m and aci==n){
    ll xd = fac[n-m];
    for (auto i = 0; i < lim; i++) 
      if(fre[i])xd=(xd*ifac[fre[i]])%mod;
    ans+=xd;
  }
  cout<<ans<<'\n';
}

