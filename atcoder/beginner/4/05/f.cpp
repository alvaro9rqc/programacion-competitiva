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

struct MergeTree {
  vector<vector<ll>> t;
  ll n;
  MergeTree(const vector<ll> &a) : n(sz(a)), t(4*sz(a)) {
    build(a, 1, 0, n-1);
  }
  void build(const vector<ll> &a, ll v, ll l, ll r) {
    if (l == r) t[v] = {a[l]};
    else {
      ll m = (l+r)/2;
      build(a, v*2, l, m);
      build(a, v*2+1, m+1, r);
      merge(all(t[v*2]), all(t[v*2+1]),
            back_inserter(t[v]));
    }
  }
  ll qry(ll v, ll tl, ll tr, ll l, ll r, ll x) {
    if (l > r) return 0;
    if (l == tl && r == tr)
      return upper_bound(all(t[v]), x) - t[v].begin();
    ll m = (tl+tr)/2;
    return qry(v*2, tl, m, l, min(r,m), x)
    + qry(v*2+1, m+1, tr, max(l,m+1), r, x);
  }
  ll query(ll l, ll r, ll x) {
    return qry(1, 0, n-1, l, r, x);
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  ll n,m;cin>>n>>m;
  vl val(n*2+10);
  for (auto i = 1; i < m+1; i++) {
    ll a, b;cin>>a>>b;
    val[a]=b;
    val[b]=a;
  }
  MergeTree mt(val);
  ll q;cin>>q;
  while(q--) {
    ll c,d;cin>>c>>d;
    ll ans = 0;
    if(c!=1) ans+=(mt.query(1,c-1,d)-mt.query(1,c-1,c-1));
    if (d!=2*n) ans+=(mt.query(d+1,2*n,d)-mt.query(d+1,2*n,c-1));
    cout<<ans<<'\n';

  }
}

