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
  int n, p;
  while(cin >> p >> n) {
    priority_queue<int, vector<int>, less<int>> pq;
    p-= n;
    for (auto i = 0; i < n; ++i) {
      int x; cin >> x;
      pq.emplace(x);
    }
    while(p--) {
      auto x = pq.top();
      if (x == 1) break;
      pq.pop();
      auto a = x>>1;
      auto b = a+(x&1);
      pq.emplace(a);
      pq.emplace(b);
    }
    cout << pq.top() << '\n';
  }
}


