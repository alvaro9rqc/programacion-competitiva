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
    bool f6 = 0, f5 = 0;
    int n; cin>>n;
    string s; cin >> s;
    f6 = s.find("2026") != string::npos;
    f5 = s.find("2025") == string::npos;
    if (f6 or f5) {
      cout << 0<<'\n';
    } else cout << 1 <<'\n';
  }

}

