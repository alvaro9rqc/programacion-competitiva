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
  string s;cin>>s;
  set<int>osb, osc;
  for (auto i = 0; i < sz(s); i++) {
    if (s[i]=='B') osb.emplace(i);
    if (s[i]=='C') osc.emplace(i);
  }
  int ans = 0;
  for (auto i = 0; i < sz(s); i++) {
    if (s[i]!='A')continue;
    auto itb = osb.upper_bound(i);
    if (itb==osb.end()) continue;
    auto itc = osc.upper_bound(*itb);
    if (itc==osc.end()) continue;
    ++ans;
    osb.erase(itb);
    osc.erase(itc);
  }
  cout<<ans<<'\n';
}

