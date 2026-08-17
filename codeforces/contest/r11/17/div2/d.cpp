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

tuple<vl, vl,vl> f(ll s) {
  vl hrr,wrr,prr;
  for (auto i = 1ll; i*i <= s; i++) {
    if(s%i==0) {
      ll j = s/i;
      wrr.emplace_back(i);
      if(j!=i)wrr.emplace_back(j);
    }
  }
  sort(all(wrr));
  prr.resize(sz(wrr));
  hrr.resize(sz(wrr));
  prr[0]=s;
  hrr[0]=s;
  for (auto i = 1; i < sz(wrr); i++) {
    hrr[i]=s/wrr[i];
    prr[i]=prr[i-1]+(wrr[i]-wrr[i-1])*hrr[i];
  }
  return {hrr,wrr,prr};
}

void solve() {
  ll s,_;cin>>s>>_;
  auto [hrr,wrr,prr] = f(s);
  int n = sz(wrr);
  // for(auto& i: prr) cout<<i<<' ';
  // raya;

  for (auto i = 0; i < _; i++) {
    ll x, y;cin>>x>>y;
    ll ans = 0;
    int ix = int(lower_bound(all(wrr), x) - wrr.begin());
    if(wrr[ix]>x) {
      --ix;
      ans+=min(y,hrr[ix+1])*(x-wrr[ix]);
    }
    // int iy = 0;
    int iy = n-1-int(
      lower_bound(hrr.rbegin()+n-ix-1, hrr.rend(), y) - hrr.rbegin()
    );
    // dbg(ans);
    // dbg(ix);
    // dbg(iy);
    ans+=wrr[iy]*y;
    ans+= prr[ix]-prr[iy];
    cout<<ans<<'\n';
  }
  // raya;
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

