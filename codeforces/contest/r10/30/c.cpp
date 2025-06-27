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
  int tt; cin>> tt;
  while(tt--) {
    ll n, k; cin >> n >>k;
    vl a(n); 
    priority_queue<ll, vl, greater<ll>> pq;
    ll ans = 0;
    for(auto& e: a) cin >> e;
    for (auto j = 0; j < n; ++j) {
      ll x = a[j];
      ll y = x;
      for (auto i = 0; i < 62; ++i) {
        if (x & 1ll<<i) ++ans;
        y |= 1ll<<i;
        if (y - x) pq.push(y-x), x=y; 
      }
    }
    while(not pq.empty() and pq.top() <= k) {
      ++ans;
      k -= pq.top();
      pq.pop();
    }
    cout << ans <<'\n';
  }
}


