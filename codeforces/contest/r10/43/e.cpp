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
    int n,m, q; cin >> n>>m >> q;
    vl arr(n), brr(m);
    map<ll,int> rep;
    for(auto& i: arr) cin >> i;
    for(auto& i: brr) cin >> i;
    sort(all(arr));
    sort(all(brr));
    for(auto& i: arr) rep[i]++;
    vl mer(n+m);
    vector<ii> cnt(n+m);
    merge(all(arr), all(brr), mer.begin());
    for (auto i = n+m-1, x=0, y=0; i >= 0; i--) {
      if (rep[mer[i]]) {
        cnt[i] = {++x, y};
        rep[mer[i]]--;
      } else cnt[i] = {x, ++y};
    }
    arr.emplace_back(0);
    brr.emplace_back(0);
    //for(auto& [a,b]: cnt) cout << a <<' ' << b <<'\n';
    for (auto i = n-2; i >=0; i--) arr[i]+=arr[i+1];
    for (auto i = m-2; i >=0; i--) brr[i]+=brr[i+1];
    for (auto q_ = 0; q_ < q; q_++) {
      int x, y, z; cin>>x>>y>>z;
      if (z == 0) {cout << 0 << '\n'; continue;}
      auto [cx,cy] = cnt[n+m-z];
      if (cx>x) {
        cout << arr[n-x]+brr[m-z+x]<<'\n';
      } else if (cy > y) { cout << brr[m-y]+arr[n-(z-y)]<<'\n'; }
      else cout << arr[n-cx]+brr[m-cy]<<'\n';
    }
  }
}


