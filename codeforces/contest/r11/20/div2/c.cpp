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

void solve() {
  int n;cin>>n;
  set<ll> ost;
  for (ll i = 0; i < n; i++) ost.emplace(i);
  for (ll i = 1; i < n+1; i++) {
    ll m;cin>>m;
    for (auto it = ost.lower_bound(i*m); it!=ost.end() and *it<i*(m+1);) {
      it = ost.erase(it);
    }
  }
  cout<<sz(ost)<<'\n';
  for(auto& i: ost) cout<<i<<' ';
  cout<<'\n';
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

