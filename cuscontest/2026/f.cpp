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
  int j,s;cin>>j>>s;
  vector<ii> prr(j);
  for(auto& [l,r]: prr) cin>>l>>r;
  sort(prr.rbegin(), prr.rend());
  int ans=0;
  multiset<int>oms;
  for(auto& [l,r]: prr) {
    auto it = oms.lower_bound(r);
    if(it==oms.end()) {
      if(sz(oms)<s)++ans,oms.emplace(l);
    } else {
      oms.erase(it);
      oms.emplace(l);
      ++ans;
    }
  }
  cout<<ans<<'\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt=1;
  // cin>>tt;
  while(tt--) {
    solve();
  }
}

