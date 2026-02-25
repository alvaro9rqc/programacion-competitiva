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
  int n, q; cin >> n >> q;
  vl arr(n); for(auto& i: arr) cin>>i;
  sort(all(arr));
  auto s= [&arr](ll ans, ll j, bool& f) {
    auto it = upper_bound(all(arr), j);
    ans-=ll(it-arr.begin());
    if (it!=arr.begin() and *(--it) == j)f=1;
    return ans;
  };
  for (auto i = 0; i < q; i++) {
    ll x, y; cin >> x >> y;
    ll l = x, r = x+ll(2*1e9);
    ll xd = ll(lower_bound(all(arr), x)-arr.begin());
    while(l<r){
      ll m = (l+r)/2;
      bool ist=0;
      ll z = s(m-x+1+xd,m,ist);
      //dbg(l);
      //dbg(r);
      //dbg(m);
      //dbg(z);
      //raya;
      if (z == y) {
        //if (find(all(arr),m)==arr.end()) 
        if (!ist) 
          l=r=m;
        else r=m-1;
      }
      else if (z < y) {
        l=m+1;
      } else r=m-1;
    }
    cout << l <<'\n';
  }
}

