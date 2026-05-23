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
  ll ma=-1,mi=1e10;
  for (auto i = 0; i < n; i++) {
    ll x;cin>>x;
    ma=max(ma,x);
    mi=min(mi,x);
  }
  ll ans = 1e10;
  for (auto i = mi; i < ma+1; i++) {
    ans=min(ans, max(i-mi,ma-i));
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

