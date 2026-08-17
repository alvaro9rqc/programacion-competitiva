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
  int n,m;cin>>n>>m;
  set<char> oms;
  for (auto i = 0; i < n; i++) {
    string s;cin>>s;
    oms.emplace(s.front());
  }
  bool can = 1;
  for (auto i = 0; i < m; i++) {
    string p;cin>>p;
    for(auto& c: p) {
      c-='A';
      if (! oms.count(c+'a')) {can=0;}
    }
  }
  cout<<(can?"yes":"no")<<'\n';
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

