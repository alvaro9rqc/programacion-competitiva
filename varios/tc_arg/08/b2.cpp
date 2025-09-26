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
  int ab, de, med;
  ab = de = med = 0;
  string s; cin >> s;
  for(auto& b: s) {
    // ver
    if (b == '0') {
      if (ab) {
        cout << "1 1\n";
        ab = 0;
      }  else {
        cout << "3 1\n";
        ab = 1;
      }
    } else {
      if (de) {
        cout << "1 1\n";
        de = 0;
      } else {
        cout << "1 3\n";
        de = 1;
      }
    }
  }
  
}


