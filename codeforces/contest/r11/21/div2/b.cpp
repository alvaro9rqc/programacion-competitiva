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

void solve() {
  int n,m;cin>>n>>m;
  vl arr(n);for(auto& i: arr) cin >> i;
  vl ids(n), idi(n);
  iota(all(ids), 0);
  sort(all(ids), [&arr](int a, int b) {
    return arr[a]<arr[b];
  });
  for (auto i = 0; i < n; i++) {
    idi[ids[i]]=i;
  }
  // for(auto& i: ids) {cout<<i<<' ';}cout<<'\n';
  // for(auto& i: idi) {cout<<i<<' ';}cout<<'\n';
  FT fs(n), ps(n);
  ll ans = -1*(1e17);
  for (auto i = 0; i < n; i++) {
    auto s = ps.query((int)idi[i]);
    auto f = fs.query((int)idi[i]);
    // dbg(i);
    // dbg(s);
    // dbg(f);
    ans=max(ans, (f+1)*arr[i]-s);
    ps.update((int)idi[i],arr[i]);
    fs.update((int)idi[i],1);
  }
  cout<<ans<<'\n';
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

