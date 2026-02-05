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
  int n, m; cin >> n >> m;
  vi arr(n); for(auto& i: arr) cin>>i;
  vector<vi> cp, cn;
  int aux = 0;
  for (; aux < n and arr[aux]; aux++) ;
  while(aux<n) {
    cp.emplace_back();
    cn.emplace_back();
    auto j = aux+1;
    for (; j < n and arr[j]; j++) {
      if (arr[j]<0) cn.back().emplace_back(-arr[j]);
      else cp.back().emplace_back(arr[j]);
    }
    sort(all(cp.back()));
    sort(all(cn.back()));
    aux=j;
  }
  vector<vi>dp(m+1, vi(m+2));
  auto pts=[&](int i, int p) {
    int ans  = 0;
    ans+=int(
      upper_bound(all(cp[i]), p)-cp[i].begin()
    );
    ans+=int(
      upper_bound(all(cn[i]), max(i+1-p,0)) - cn[i].begin()
    );
    return ans;
    // cp[i].upper_bound(p)
  };
  for (auto i = m-1; i >= 0; i--) {
    for (auto p = 0; p <= i+1; p++) {
      dp[i][p]=max(
        pts(i,p)+dp[i+1][p],
        pts(i,p+1)+dp[i+1][p+1]
      );
    }
  }
  cout<<dp[0][0]<<'\n';
}


