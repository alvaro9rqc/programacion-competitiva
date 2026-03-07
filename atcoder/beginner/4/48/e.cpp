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

const ll mod = 10007;
ll fe(ll b, ll e) {
  ll r = 1;
  while(e) {
    if(e&1) r*=b,r%=mod;
    e>>=1;
    b*=b;b%=mod;
  }
  return r;
}

ll prec[]={0,1,11,111};

ll f11(ll l) {
  if (l<4)return prec[l];
  ll x = l/2;
  ll rx = f11(x);
  if(l-x==x) return (rx+rx*fe(10,x))%mod;
  else return (rx+rx*fe(10,x+1)+1)%mod;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  // dbg(fe(10,5));
  int k;cin>>k;
  ll m;cin>>m;m=fe(m,mod-2);
  ll n = 0;
  vector<pair<ll,ll>> xd(k);
  for(auto& [c,l]: xd) cin>>c>>l;
  reverse(all(xd));
  ll acc=0;
  for(auto& [c,l]: xd) {
    n+=f11(l)*c*fe(10,acc);
    n%=mod;
    acc+=l;
  }
  cout<<(n*m%mod)<<'\n';
  dbg(m);
  dbg(n);
  dbg(316227766ll*m%mod);
  dbg(fe(45175395,mod-2));
  dbg(fe(10,mod-2));
}

