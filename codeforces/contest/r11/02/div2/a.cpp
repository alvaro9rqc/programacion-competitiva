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
  vl val(n); for(auto& i: val) cin >> i;
  sort(val.rbegin(), val.rend());
  bool can = 1;
  for (auto j = 2; j < n; j++) {
    if(val[j]!=(val[j-2]%val[j-1])) can=0;
  }
  if(not can) {
    cout<<"-1\n";
  } else {
    cout<<val[0]<<' '<<val[1]<<'\n';
  }
  // for (auto i = 0; i < n; i++) {
  //   vl xd = {val[i]};
  //   bool can = 1;
  //   for (auto j = 0; j < n; j++) 
  //     if(j!=i)xd.emplace_back(val[j]);
  // }
  // cout<<"-1\n";
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

