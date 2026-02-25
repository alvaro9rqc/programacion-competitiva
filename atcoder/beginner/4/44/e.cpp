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
  int n, d;cin>>n>>d;
  vi arr(n); for(auto& i: arr) cin>>i;
  multiset<int> mse;
  auto ev= [&](int j) {
    if (j==n) return 0;
    auto it = mse.upper_bound(arr[j]);
    if (it!=mse.end() and *it-arr[j]<d) {
      return 0;
    }
    if (it!=mse.begin() and arr[j]-*(--it)<d) {
      return 0;
    }
    return 1;
  };
  mse.emplace(arr[0]);
  ll ans = 0;
  for (auto i = 0,j=1; i < n; ) {
    if (ev(j)) mse.emplace(arr[j++]);
    else {
      // ans+=(j-i)*1ll*(j-i+1)/2;
      ans+=j-i;
      // dbg(i);
      // dbg(j);
      mse.erase(mse.find(arr[i++]));
    }
  }
  cout<<ans<<'\n';
}

