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
    int n,k; cin >> n>>k;
    vi arr(n);
    for(auto& i: arr) cin >> i;
    set<int> nus;
    for (auto i = 1; i < n+1; i++) nus.insert(i);
    for(auto& i: arr) nus.erase(i);
    if (not sz(nus)) {
      for (auto i = 0; i < k; i++) cout << arr[i]<<' ';
      cout << '\n';
    } else {
      set<int>disp;
      for (auto i = 1; i < n+1; i++) disp.insert(i);
      int e = 1;
      int f=*nus.begin();
      cout << (*nus.begin()) <<' ';
      disp.erase(*nus.begin());
      nus.erase(nus.begin());
      for (auto i = e; i < k; i++) {
        if (i == 1) {
          int x=-1;
          for (auto j = 1; j < n+1; j++) 
            if (j != f and j != arr.back()) {
              x = j;
              break;
            }
          if (x ==-1) x=arr.back();
          cout << x <<' ';
          disp.erase(x);
        } else {
          cout << (*disp.begin()) <<' ';
          disp.erase(disp.begin());
        }
      }
      cout << '\n';
    }
  }
}

