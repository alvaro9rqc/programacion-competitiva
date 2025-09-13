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
    vl arr(n);
    for(auto& i: arr) cin>>i;
    ll ans = 0;
    sort(all(arr));
    int imp = 0;
    for(auto& i: arr) if (i&1)++imp;
    if (imp)
      imp = imp/2+(imp&1);
    int c = 0;
    for (auto i = n-1; i >=0; i--) {
      if (arr[i]&1 and c < imp) ans+=arr[i],++c;
    }
    if (ans) for(auto& i: arr) if (!(i&1))ans+=i;
    cout << ans <<'\n';
  }
}

