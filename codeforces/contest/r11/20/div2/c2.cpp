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

using pl = pair<ll,ll>;

void solve() {
  int n;
  cin>>n;
  set<ll> ost;
  vl val;
  for (ll i = 0; i < n; i++) ost.emplace(i);
  for (ll i = 1; i < n+1; i++) {
    ll m;cin>>m;
    val.emplace_back(m);
    for (auto it = ost.lower_bound(i*m); it!=ost.end() and *it<i*(m+1);) {
      it = ost.erase(it);
    }
  }

  auto f = [&]() {
    int m = sz(ost);
    vl arr(all(ost));
    vl pre(n,-1);
    vl nex(n,-1);
    for (auto i = 0; i < m; i++) pre[arr[i]]=i;
    for (auto i = 0; i < m; i++) nex[arr[i]]=i;
    for (auto i = 1; i < n; i++) if(pre[i]==-1) pre[i]=pre[i-1];
    for (auto i = n-2; i >= 0; i--) if(nex[i]==-1) nex[i]=nex[i+1];
    vector<pl> p;
    for (auto i = 1; i < n+1; i++) {
      for (auto j = 0; j < val[i-1]; j++) 
        p.emplace_back(nex[j*i],pre[min(n-1,(j+1)*i-1)]);
    }
    vl ml(n,-1);
    for(auto& [l,r]: p) ml[r]=max(l,ml[r]);
    vector<pl> pf;
    ll l_m=-1;
    for (auto i = 0; i < n; i++) {
      if(ml[i]!=-1 and l_m<ml[i]) {
        l_m = ml[i];
        pf.emplace_back(l_m+1, i+1);
      }
    }
    return pf;
  };
  auto pf = f();
  int m = sz(ost);
  vl dp(m+2);
  vl ps(m+2);
  dp[0]=1;
  ps[0]=1;
  int xd = 0;
  ll mod = 1e9+7;
  ll piv = 0;
  for (auto i = 1; i <= m+1; i++) {
    while(xd<sz(pf) and pf[xd].second<i)piv = max(piv,pf[xd++].first);
    dp[i]=(ps[i-1]-(piv?ps[piv-1]:0)+mod)%mod;
    ps[i]=(ps[i-1]+dp[i])%mod;
  }
  cout<<dp[m+1]<<'\n';
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

