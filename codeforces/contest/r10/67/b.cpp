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
    n*=2;
    map<int,int> mp;
    for (auto i = 0; i < n; i++) {
      int x; cin >> x;
      mp[x]++;
    }
    vi arr;
    for(auto& [k,v]: mp) arr.emplace_back(v);
    int imp, pr, pz;
    pr=pz=imp=0;
    for(auto& i: arr) {
      if (i &1) ++imp;
      else if ((i/2)&1) pz++;
      else pr++;
    }
    int ans = imp+pr*2+pz*2;
    //dbg(imp);
    //dbg(pr);
    //dbg(pz);
    if (pr&1) {
      if (sz(arr) == 1) ans = 0;
      else {
        if (not(imp > 0)) ans-=2;
      }
    }
    cout << ans <<'\n';
  }
}

