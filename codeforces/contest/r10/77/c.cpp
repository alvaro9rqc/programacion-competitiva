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
  int tt; cin >> tt;
  while(tt--) {
    int n; cin >> n;
    vl arr(n); for(auto& i: arr) cin>>i;
    auto cop = arr;
    sort(all(cop));
    set<int> s;
    ll mi = 1e10;
    ll ma = 0;
    for (auto i = 0; i < n; i++) {
      mi=min(mi,arr[i]);
      ma=max(ma,arr[i]);
      if(cop[i]!=arr[i])s.emplace(arr[i]);
    }
    if (s.empty()) {
      cout << "-1\n";
      continue;
    }
    ll ans = 1e10;
    for(auto& i: s) {
      ll x = max(i-mi,ma-i);
      ans=min(ans,x);
    }
    cout<<ans<<'\n';
  }
}

