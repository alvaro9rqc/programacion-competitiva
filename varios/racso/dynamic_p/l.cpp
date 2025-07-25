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
#define sz(x) (ll)(x).size()
#define all(x) begin(x), end(x)

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n; cin >> n;
  vl a(n);
  for(auto& e: a) cin >> e;
  vl help;
  for (ll i = 0; i < n; ++i) {
    auto it = lower_bound(all(help), a[i]);
    if (it == help.end()) {
      help.emplace_back(a[i]);
    } else {
      *it = a[i];
    }
  }  
  cout << sz(help) <<'\n';
}


