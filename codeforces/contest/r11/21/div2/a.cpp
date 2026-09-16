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
  vi p, ids;
  for (auto i = 0; i < n; i++) {
    int x;cin>>x;
    p.emplace_back(x);
    if(x!=i+1) ids.emplace_back(i);
  }
  vi pc = p;
  for (auto i = 0; i < sz(ids); i++) {
    pc[ids[i]]=p[ids[sz(ids)-i-1]];
  }
  // for(auto& i: ids) cout<<i<<' ';
  // cout<<'\n';
  // for(auto& i: pc) cout<<i<<' ';
  // cout<<'\n';
  // for(auto& i: p) cout<<i<<' ';
  // cout<<'\n';
  sort(all(p));
  cout<<(pc==p?"YES":"NO")<<'\n';
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

