#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
#define endl '\n'
#define dbg(x) cerr << #x << " = " << (x) << endl;
#define raya cerr << " ==================== " << endl;
#define FOR(i, a, b) for (auto i = a; i < (b); ++i)
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt; cin>> tt; 
  while(tt--) {
    int n; cin>>n;
    vector<ii> p(n);
    vi ans;
    for(auto& [l,r]: p) cin >> l >> r;
    vi idx(n);
    iota(all(idx), 0);
    sort(all(idx), [&p](int pa, int pb){
        auto& a = p[pa];
        auto& b = p[pb];
        if (a.first == b.first) {
          return a.second > b.second;
        }
          return a.first < b.first;
        });
    //sort(all(p), [](ii& a, ii& b){});
    //for(auto& [l,r]: p) cout << l << ' '<<r <<'\n';
    int b = 0, e = 0;
    for (auto i = 0; i < n; ++i) {
      auto [l, r] = p[idx[i]];
      if (r > e) {
        ans.emplace_back(idx[i]);
        b = l, e = r;
      } 
    }
    cout << sz(ans) << '\n';
    for(auto& x: ans) cout << (x+1) << ' ';
    cout << '\n';
  }
}


