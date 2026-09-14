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
  ll rs(int l, int r) {return query(r) - query(l);}
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
  int n;cin>>n;
  FT ps(n+1);
  vl arr(n+1);for (auto i = 1; i < n+1; i++) cin>>arr[i];
  vl ans(n);
  vi per(n); for(auto& i: per) cin>>i;
  set<int> mur;
  ps.update(per.back(), arr[per.back()]);
  mur.emplace(0);
  mur.emplace(per.back());
  ans.back()=0;
  for (auto xd = n-2; xd >= 0; xd--) {
    //
    // for(auto& i: mur) {cout<<i<<' ';}cout<<'\n';
    // 
    int i = per[xd];
    auto pre = mur.upper_bound(i);
    auto nex =pre--;
    ps.update(i,arr[i]);
    //si nuevo muro
    ll s = 0;
    s = ps.rs(*pre,i);
    if(s<arr[i]) pre=mur.emplace(i).first;
    while(nex!=mur.end()) {
      s = ps.rs(*pre, *nex);
      if(s<arr[*nex]) break;
      else 
        nex=mur.erase(nex);
    }
    ans[xd]=sz(mur)-2;
    //
    // for(auto& i: mur) {cout<<i<<' ';}cout<<'\n';
    //
  }
  for(auto& i: ans) cout<<i<<' ';
  cout<<'\n';
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

