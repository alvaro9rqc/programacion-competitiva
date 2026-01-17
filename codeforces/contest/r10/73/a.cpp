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
  int tt;cin >> tt;
  while(tt--) {
    int n; cin >> n;
    vector<ii> arr(n);
    for (auto i = 0; i < n; i++) {
      int x; cin >> x;
      arr[i]={x,(i%2)};
    }
    sort(all(arr));
    bool can = 1;
    for (auto i = 1; i < n; i++) {
      if (arr[i-1].second==arr[i].second)can=0;
    }
    cout << (can?"YES":"NO")<<'\n';
  }
}

