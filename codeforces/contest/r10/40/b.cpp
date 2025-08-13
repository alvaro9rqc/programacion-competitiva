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
  int tt; cin >> tt;
  while(tt--) {
    int n, s;
    cin >> n >> s;
    vi a(n);
    int sum = 0;
    int v0, v1,v2;
    v0=v1=v2=0;
    for(auto& e: a) {
      cin >> e;
      if (e == 0)++v0;
      if (e == 1)++v1;
      if (e == 2)++v2;
      sum+=e;
    }
    int e = s - sum;
    if (e < 0) {
      for(auto& x: a) cout << x <<' ';
      cout << '\n';
    } else if (e == 0) {
      cout << -1 <<'\n';
    } else if (e == 1) {
      for (auto i = 0; i < v0; ++i) cout << 0 << ' ';
      for (auto i = 0; i < v2; ++i) cout << 2 << ' ';
      for (auto i = 0; i < v1; ++i) cout << 1 << ' ';
      cout  << '\n';
    } else {
      cout << -1;
      cout  << '\n';
    }
  }
}


