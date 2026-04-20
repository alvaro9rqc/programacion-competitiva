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
  ll n,k,h,w;cin>>n>>k>>h>>w;
  using vll=vector<pair<ll,ll>>;
  vector<vll> bj(1,vll(n));
  for (auto i = 0; i < n; i++) {
    cin>>bj[0][i].first;
    bj[0][i].second=(i+k)%n;
  }
  for (auto lev = 1; (1ll<<lev)<=h; lev++) {
    bj.emplace_back(n);
    for (auto i = 0; i < n; i++) {
      ll j = bj[lev-1][i].second;
      bj[lev][i].first=bj[lev-1][i].first+bj[lev-1][j].first;
      bj[lev][i].second=bj[lev-1][j].second;
    }
  } 
  vl kad(n);
  for (auto i = 0; i < n; i++) {
    ll x = i;
    for (auto j = 0; (1ll<<j)<=h; j++) {
      if(1ll<<j&h) {
        auto [s,ni]=bj[j][x];
        kad[i]+=s;
        x=ni;
      }
    }
    // dbg(kad[i]);
  }

  ll sum=0;
  for (auto i = 0; i < w; i++) sum+=kad[i];
  vl alt={sum};
  for (auto i = 1; i < n; i++) {
    sum+=kad[(i+w-1)%n]-kad[i-1];
    alt.emplace_back(sum);
    // dbg(sum);
  }
  vl ava(2*n);
  for (auto i = 0ll,x=0ll; i < n-h+1; i++) {
    ++ava[x];
    --ava[x+(n-w+1)];
    x=(x+k)%n;
  }
  ll ans = alt.front();
  ll xd=0;
  for (auto i = 0; i < sz(ava); i++) {
    xd+=ava[i];
    // dbg(i);
    // dbg(ava[i])
    if(xd>0) ans=max(ans,alt[i%n]);
  }
  cout<<ans<<'\n';
}

