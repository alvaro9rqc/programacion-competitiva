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

const int nm = int(2*1e5+3);

vector<vector<int>> divs(nm);

void pre() {
  for (auto i = 1; i < nm; i++) 
    for (auto j = i; j < nm; j+=i) divs[j].emplace_back(i);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt; cin >> tt;
  pre();
  while(tt--) {
    int n; cin >> n;
    vi arr(n);
    for(auto& i: arr) cin >> i;
    vi cd(n+1);
    vi ans(n);
    auto update=[&ans](int i, int f) {
      int a = f*(f<=i);
      int b = i?ans[i-1]:0;
      ans[i]=max({a,b,ans[i]});
    };
    for(auto& d: divs[arr[0]]) update(0, ++cd[d]);
    for (auto i = 1; i < n; i++) {
      for(auto& d: divs[arr[i]]) update(i, ++cd[d]);
      for(auto& d: divs[arr[i-1]]) update(i, cd[d]);
    }
    for(auto& d: ans) cout << d <<' ';
    cout <<'\n';
  }

}

