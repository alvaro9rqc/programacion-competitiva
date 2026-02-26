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
  int tt;cin>>tt;
  while(tt--) {
    int n;cin>>n;
    vector<vi> tot;
    for (auto i = 0; i < n; i++) {
      int l;cin>>l;
      tot.emplace_back(l);
      for(auto& j: tot.back())cin>>j;
      reverse(all(tot.back()));
    }
    sort(all(tot));
    set<int> ose;
    vi ans;
    for(auto& v: tot) {
      for(auto& i: v) {
        if (not ose.count(i)) {
          ans.emplace_back(i);
          ose.emplace(i);
        }
      }
    }
    for(auto& i: ans) cout<<i<<' ';
    cout<<'\n';
  }
}

