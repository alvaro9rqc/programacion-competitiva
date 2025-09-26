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

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt; cin >> tt;
  while(tt--) {
    int n; cin >> n;
    cout << 2*n -1<<'\n';
    cout << "1 1 " << n << '\n';
    for (auto i = 1; i < n; ++i) {
      cout << i+1 << " 1" << " " << i << '\n';
      cout << i+1 << " " <<i+1 << " " << n << '\n';
    }
  }
}


