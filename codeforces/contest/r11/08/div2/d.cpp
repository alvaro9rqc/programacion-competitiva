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

pair<ll,ll> f( ll x) {
  ll r = 0;
  ll t=0;
  while(!(x&1)) {
    ++r;x>>=1;
  }
  t=r;
  while(x){
    ++t;
    if(x&1)--x;
    else x>>=1;
  }
  return {r,t};
}

void solve() {
  ll n;cin>>n;
  ll c = 0;
  ll s = 0;
  ll d = 30;
  vector<vl> val(30);
  for (auto p = 0; p < n; p++) {
    ll x;cin>>x;
    auto [p2, pts] = f(x);
    val[p2].emplace_back(x);
    s+=pts;
    d=min(p2,d);
  }
  ll ans = c+s-n*d+d;
  // for(auto& i: val[0]) cout<<i<<' ';
  // cout<<'\n';
  for(;d<30 and c<ans;++d){
    // dbg(ans);
    // dbg(s);
    // dbg(c);
    // dbg(d);
    // dbg(c+s-n*(d)+d);
    for (auto i = 0; i < sz(val[d]); i++) {
      ans = min(ans,c+s-n*d+d);
      //new
      ll p = (1ll<<(d+1));
      ll x1 = (-val[d][i]%p);
      if(x1)x1+=p;
      ll x = val[d][i];
      x1+=x;
      //tra
      c+=x1-x;
      auto [p0,pts0]=f(x);
      auto [p1,pts1]=f(x1);
      s+=pts1-pts0;
      val[p1].emplace_back(x1);
    }
  }
  cout<<ans<<'\n';
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

