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
  int tt ; cin >> tt;
  while(tt--) {
    int n, m, q; cin >> n >> m >> q;
    vl arr(n), brr(m);
    for(auto& i: arr) cin >> i;
    for(auto& i: brr) cin >> i;
    sort(all(arr));
    sort(all(brr), greater<int>());
    vl psm(n+m), joi(n+m), id(n+m);
    iota(all(id), 0ll);
    psm[0] = joi[0] = arr[0];
    for (auto i = 1; i < n; i++) psm[i]= arr[i]+psm[i-1], joi[i]=arr[i];
    for (auto i = n; i < m+n; i++) psm[i]= brr[i-n]+psm[i-1], joi[i]=brr[i-n];
    joi.emplace_back(0);
    id.emplace_back(0);
    auto sum = [&psm](ll i, ll j) {
      if (j < i) return 0ll;
      return (psm[j]-(i==0?0ll:psm[i-1]));
    };
    for (auto q_ = 0; q_ < q; q_++) {
      ll x, y, z; cin >> x >> y >> z;
      if (z == 0) {cout << 0 <<'\n'; continue;}
      auto it = id.begin()+n-x;
      auto it2 = id.begin()+n+y-z+1;
      dbg(*it);
      dbg(*it2);
      //auto it2 = min(id.begin()+n+y, id.begin()+n+y-z+1);
      auto it3 = partition_point(it, it2, [&joi, &z](int i) {
          return joi[i+z]-joi[i]>=0;
          });
      ll d1 = *it3;
      ll d2 = d1+z-1;
      cout << (joi[1+1]-joi[1]>=0)<<'\n';
      if (it3 == it2)--d1, --d2;
      ll ans =sum(d1,d2);
      dbg(d1);
      dbg(d2);
      //if (d2-n+1<y)ans=max(ans, sum(d1+1,d2+1));
      //if (n - d1 < x) ans = max(ans, sum(d1-1, d2-1));
      cout << ans <<'\n';
    }
  }
}


