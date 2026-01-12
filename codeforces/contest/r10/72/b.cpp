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
    ll s, k, m; cin >> s >> k >> m;
    ll x=m/k+1;
    ll t = m%k;
    ll ans =0;
    if (k>=s){
      ans=max(0ll, s-t);
    } else {
      if(x&1) ans=max(0ll,s- t);
      else ans=max(0ll,k-t);
    }
    cout << ans <<'\n';
  }
}

