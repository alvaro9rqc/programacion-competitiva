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
  if(n==1) {
    cout<<1<<'\n';
  } else if(n==2) {
    cout<<"-1\n";
  } else {
    vl ans = {1,2};
    ll m = 1;
    while(sz(ans)!=n) {
      ans.emplace_back(m*3);
      m<<=1;
    }
    for(auto& i: ans) cout<<i<<' ';
    cout<<'\n';
  }
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

