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

ll f(ll x) {
  ll ans = 0;
  while(x>1) {
    ans++;
    x>>=1;
    if(x==1)break;
    ++x;
  }
  return ans;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt;cin>>tt;
  while(tt--) {
    int n, q;cin>>n>>q;
    vl pts(n+1), imp(n+1);
    for (auto i = 1; i < n+1; i++) {
      ll x;cin>>x;
      ll p = f(x);
      pts[i]=p+pts[i-1];
      imp[i]=f(x+1)-p+imp[i-1];
    }
    for (auto i = 0; i < q; i++) {
      int l, r;cin>>l>>r;
      // dbg(pts[r]-pts[l-1]);
      // dbg(imp[r]+imp[l-1]);
      cout<<(pts[r]-pts[l-1]+(imp[r]-imp[l-1])/2)<<'\n';
    }
  }
}

