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
  ll n, m;cin>>n>>m;
  vl crr(m); for(auto& i: crr) cin>>i;
  vl ans(m);
  for (auto i = 0; i < n; i++) {
    ll t, c;cin>>t>>c;
    ans[t-1]+=c;
  }
  ll a = 0;
  for (auto i = 0; i < m; i++) {
    a+=min(ans[i],crr[i]);
  }
  cout<<a<<'\n';
}

