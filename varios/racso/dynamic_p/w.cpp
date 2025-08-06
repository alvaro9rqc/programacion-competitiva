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

ll mod = 1e9+7;
inline ll f(ll x) {return (x % mod + mod) % mod;}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  ll n, k; cin >> n >> k;
  vl nw(k+1), rt(k+1);
  vl a(n); 
  for(auto& e: a) cin >> e;
  rt[0] = 1;
  for (auto i = 1; i <= k; ++i) 
    rt[i] = (i <= a.back()? 1:0) + rt[i-1], rt[i]%=mod;
  for (auto i = n-2; i >= 0; --i) {
    //for(auto& e: rt) cout  << e << ' ';
    //cout << '\n';
    for (auto c = 0; c <= k; ++c) {
      auto x = (max(0ll, c-a[i]));
      nw[c] = rt[c] - (x?rt[x-1]:0);
      nw[c] = f(nw[c]);
      if (c) nw[c] += nw[c-1];
      nw[c] %= mod;
    }
    swap(nw, rt);
  }
  auto ans = rt[k] - (k?rt[k-1]:0);
  cout << f(ans) << '\n';
}


