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
    ll n, w; cin >> n >> w;
    vl arr(n);
    for(auto& i: arr) cin>>i;
    vl sl(2*w);
    for (auto i = 0; i < n; i++) {
      sl[(i+1)%(2*w)]+=arr[i];
    }
    ll sum = 0;
    for (auto i = 0; i < w; i++) sum+=sl[i];
    ll ans = sum;
    for (auto i = 0ll,j=w; i < 2*w; i++, j=(j+1)%(2*w)) {
      sum=sum-sl[i]+sl[j];
      ans=min(ans,sum);
    }
    cout << ans <<'\n';
  }
}

