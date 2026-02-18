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

vl pri;
const ll lim = 1e4+10;
bitset<lim> bs;
ll mod = 998244353;

struct P {
  ll p, e, t;
};

vector<vector<P>> fac;

ll inv(ll b) {
  ll e = mod-2;
  ll r = 1;
  while(e) {
    if(e&1)r*=b,r%=mod;
    e>>=1;
    b=b*b%mod;
  }
  return r;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  bs.set();
  bs[0]=bs[1]=0;
  for (auto i = 2ll; i < lim; i++) {
    if(bs[i]) {
      for (auto j = i*i; j < lim; j+=i) bs[j]=0;
      pri.emplace_back(i);
    }
  }
  // dbg(pri[1]);
  ll tt;cin>>tt;
  while(tt--) {
    ll n;cin>>n;
    fac.assign(n, {});
    for (auto i = 0; i < n; i++) {
      ll x;cin>>x;
      for(auto& p: pri) {
        if (p*p>x) break;
        while(x%p==0) {
          if(not(sz(fac[i])) or fac[i].back().p != p) {
            fac[i].emplace_back(p, 0, 1);
          }
          ++fac[i].back().e;
          fac[i].back().t*=p;
          x/=p;
        }
      }
      if (x!=1) fac[i].emplace_back(x, 1, x);
    }

    map<ll,ll> m1, m2;
    auto ins= [&](ll p, ll e) {
      if (m1.count(p)) {
        if (m1[p]<=e) m2[p] = m1[p], m1[p]=e;
        else if (m2[p]<e)m2[p]=e;
      } else m1[p]=e, m2[p]=1;
    };
    for(auto& v: fac) {
      for(auto& [p,e,t]: v) {
        ins(p,t);
      }
    }
    ll tot = 1;
    for(auto& [p,t]: m1) {
      tot*=t;
      tot%=mod;
    }
    for(auto& v: fac) {
      ll ans = tot;
      for(auto& [p,e,t]: v) {
        if(t==m1[p]) ans=ans*inv(t)%mod*m2[p]%mod;
      }
      cout<<ans<<' ';
    }
    cout<<'\n';

    // for(auto& [p,e,t]: fac[0]) {
    //   dbg(p);
    //   dbg(e);
    //   dbg(t);
    // } 
  }
}


