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

ll mod = 998244353;

inline ll inv(ll q) {
  ll ans = 1;
  ll e = mod-2;
  while(e) {
    if(e&1) ans= (ans*q)%mod;
    q= (q*q)%mod;
    e>>=1;
  }
  return ans;
}

ll mag(ll p, ll q) {
  return p*inv(q) % mod;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n, m; cin>>n>>m;
  vl dp(m+10);
  vector<vector<pair<ll,ll>>> arr(m+10);
  ll ne = 1;
  for (auto i = 0; i < n; ++i) {
    int x, y, p, q; cin >> x >> y >> p >> q;
    arr[x].emplace_back(y, mag(p,q)*mag(q,q-p) % mod);
    ne = (ne*mag(q-p, q))%mod;
  }
  for (auto i = m; i > 0; --i) {
    ll ans = 0;
    if (arr[i].size()) {
      for(auto& [r, x]: arr[i]) {
        if (r+1>m) ans= (ans+x) %mod;
        else ans+=x*dp[r+1]%mod, ans%=mod;
      }
    }
    dp[i] = ans;
  }
  //cout << mag(5, 18) << '\n';
  cout << (dp[1]*ne)%mod << '\n';
}


