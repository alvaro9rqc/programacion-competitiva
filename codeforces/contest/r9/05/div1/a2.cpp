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
  int tt;cin>>tt;
  while(tt--) {
    ll n, m;cin>>n>>m;
    multiset<ll> b;
    vl a(n-1);
    for(auto& i: a) cin>>i;
    for (auto i = 0; i < n; i++) {
      ll x;cin>>x;
      b.emplace(x);
    }
    sort(all(a));
    ll ans = 0;
    for (auto i = n-2; i >= 0; i--) {
      auto it = b.upper_bound(a[i]);
      if (it == b.end()) {
        ++ans;
      } else {
        b.erase(it);
      }
    }
    ans*=m;
    auto it = b.end();
    --it;
    ans+=max(0ll, m-*it+1);
    cout<<ans<<'\n';
  }
}

