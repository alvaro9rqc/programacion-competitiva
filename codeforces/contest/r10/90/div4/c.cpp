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
    int n;cin>>n;
    set<int> ost;
    for (auto i = 1; i < 3*n+1; i++) ost.emplace(i);
    vi ans;
    for (auto i = 0; i < n; i++) {
      auto it = ost.end();--it;
      ans.emplace_back(*it);
      ost.erase(it);
      it = ost.end();--it;
      ans.emplace_back(*it);
      ost.erase(it);
      it = ost.begin();
      ans.emplace_back(*it);
      ost.erase(it);
    }
    for(auto& i: ans) cout<<i<<' ';
    cout<<'\n';
  }
}

