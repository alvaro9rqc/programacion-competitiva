#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
#define endl '\n'
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
    vi a(n);
    for(auto& e: a) cin >> e;
    ll ans =0;
    for (auto i = 0; i < n; ++i) {
      int l=0,r=0;
      for (auto j = 0; j < i; ++j) 
        if (a[j] > a[i]) ++l;
      for (auto j = i+1; j < n; ++j) 
        if (a[j] > a[i]) ++r;
      ans+=min(l,r);
    }
    cout << ans << '\n';
  }
}


