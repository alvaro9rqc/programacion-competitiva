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
  int n,m; cin >> n >> m;
  set<char>s,t;
  for (auto i = 0; i < n; i++) {char x; cin >> x; s.insert(x);}
  for (auto i = 0; i < m; i++) {char x; cin >> x; t.insert(x);}
  int q; cin >> q;
  for (auto i = 0; i < q; i++) {
    string x; cin >> x;
    bool bt, bs;
    bt=bs=1;
    for(auto& y: x) {
      if (!t.count(y)) bt=0;
      if (!s.count(y)) bs=0;
    }
    if ((bt and bs) or (bt==0 and bs==0)) cout << "Unknown";
    else if (bt) cout << "Aoki";
    else if (bs) cout << "Takahashi";
    cout << '\n';
  }
}

