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
    int n ; cin >> n;
    vector<ii> pts(n);
    for(auto& [x,y]: pts) cin >> x >> y;
    int l,r;l = r = pts[0].first;
    for(auto& [x,y]: pts){
      l = min(l,x);
      r = max(r,x);
    }
    set<ii> left, right;
    int ml = r + l; ml = ml / 2 + (ml&1);
    int mr = r + l; mr /= 2;
    for(auto& [x,y]: pts) {
      if (x < ml) {
        auto it = right.find({mr+ml-x, y});
        if (it == right.end()) left.emplace(x,y);
        else right.erase(it);
      } else if (x > mr) {
        auto it = left.find({ml-(x-mr), y});
        if (it == left.end()) right.emplace(x,y);
        else left.erase(it);
      }
    }
    cout << ((sz(left) or sz(right))?"NO":"YES")<<'\n';
  }
}

