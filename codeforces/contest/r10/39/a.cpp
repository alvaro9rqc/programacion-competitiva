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
  while(tt--)  {
    ll n, c; cin >> n >> c;
    vl a(n);
    vl m;
    for(auto& e: a) {
      cin >> e;
      if (e <= c) m.emplace_back(e);
    }
    sort(m.rbegin(), m.rend());
    ll count = 0;
    ll mul = 1;
    for(auto& e: m) {
      ll x = e * mul;
      if (x <= c) {
        mul *= 2;
        count++;
      }
    }
    cout << n - count << '\n';
  }
}


