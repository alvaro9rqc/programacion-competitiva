#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
#define endl '\n'
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
    int n, k; cin >> n >> k;
    vi arr(n);
    for(auto& e: arr) cin >> e;
    vi bs(n);
    iota(all(bs), 1);
    int b, e;
    auto f = [&arr, &n, &b, &e, &k] (int x) {
      vi bin(n, 1);
      for(int i = 0; i < n; ++i)
        if (arr[i] < x) bin[i] = -1;
      for (auto i = 1; i < n; ++i) 
        bin[i] += bin[i-1];
      multiset<int> ms;
      for (auto i = k-1; i < n; ++i) ms.insert(bin[i]);
      //for(auto& e: ms) cout << e << ' ';
      //cout << '\n';
      bool can = 0;
      for (auto i = 0; i+k-1< n; ++i) {
        int bus = i?bin[i-1]:0;
        auto it = ms.lower_bound(bus);
        if (it != ms.end()) {
          b = i;
          for (auto j = i+k-1; j < n; ++j) 
            if (bin[j] == *it) {e = j; break;}
          can = 1; break;
        }
        ms.erase(ms.find(bin[i+k-1]));
      }
      //dbg(can);
      //dbg(x);
      //raya;
      return can;
    };
    auto it = partition_point(all(bs), f);
    --it;
    f(*it);
    cout << *(it) << ' '<<b+1<<' '<<e+1<< '\n';
  }
}


