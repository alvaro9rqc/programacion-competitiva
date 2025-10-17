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
  int tt; cin >> tt;
  while(tt--) {
    int n; cin >> n;
    vi arr(n);
    for(auto& i: arr) cin >> i;
    int ans = 0;
    for (auto i = 0; i < n; i++) {
      int sum = arr[i];
      ans=max(ans,arr[i]);
      int e = 2;
      for (auto j = i+1; j < n; j++,e++) {
        sum+=arr[j];
        ans = max(ans, sum / e);
      }
    }
    cout << ans <<'\n';
  }
}

