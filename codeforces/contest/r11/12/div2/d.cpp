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

ll lim = 1e6+4;
vl fac(lim,1);
vl ifac(lim,1);
ll mod = 998244353;

ll invm(ll b) {
  ll e = mod-2;
  ll r= 1;
  while(e) {
    if(e&1) r=(r*b)%mod;
    b=(b*b)%mod;
    e>>=1;
  }
  return r;
}

void solve() {
  int n;cin>>n;
  vl cnt(n+1);
  vl val;
  bool can =1;
  vl arr(n-1); for(auto& i: arr) cin >> i;
  for (auto r = 0,l=0; r < n; r++) {
    if(r==n-1 or arr[r]!=arr[l]) {
      if(cnt[arr[l]]) {can=0;break;}
      cnt[arr[l]]=r-l;
      val.emplace_back(arr[l]);
      l=r;
    }
  }
  for (auto i = 1,c=0; i < sz(val); i++) {
    if(!c) c+=(val[i-1]>val[i]);
    else can&=(val[i-1]>val[i]);
  }
  // dbg(val[1]);
  for(auto& i: val) can&=i>=cnt[i];
  if(!can or cnt[n] or cnt[n-1]==0) {cout<<0<<'\n'; return;}
  ll ans = 1;
  for (auto l = 0ll,r=sz(val)-1ll,la=0ll,op=0ll; l<=r;) {
    ll v=0,s=0;
    if(val[l]<val[r]) {
      v=val[l];
      ++l;
    } else {
      v=val[r];
      --r;
    }
    s=cnt[v];
    op+=v-la-1;
    if(op-s+1<0) {cout<<0<<'\n';return;}
    ans=(ans*fac[op]%mod*ifac[op-s+1]%mod)%mod;
    op-=s-1;
    la=v;
  }
  cout<<(ans*2%mod)<<'\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt=1;
  cin>>tt;
  for (auto i = 2; i < lim; i++) fac[i]=i*fac[i-1]%mod,ifac[i]=invm(fac[i]);
  while(tt--) {
    solve();
  }
}

