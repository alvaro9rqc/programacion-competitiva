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

ll mod = 998244353;

ll ex(ll e) {
  ll b=1;
  ll bas = 2;
  while(e) {
    if (e&1) b*=bas, b%=mod, --e;
    else bas*=bas, bas%=mod, e>>=1; 
  }
  return b;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt; cin >> tt;
  while(tt--) {
    ll n; cin >> n;
    vl P(n), Q(n); 
    for(auto& e: P) cin >> e;
    for(auto& e: Q) cin >> e;
    int p=0, q=0;
    for (int i = 0; i < n; ++i) {
      ll ans = 0;
      if (P[i] > P[p]) p = i;
      if (Q[i] > Q[q]) q = i;
      if (P[p] == Q[q]) {
        if (Q[i-p] > P[i-q]) ans = max(ans, (ex(P[p]) + ex(Q[i-p]))%mod);
        else ans = max(ans, (ex(P[i-q]) + ex(Q[q]))%mod);
      } else if (P[p] < Q[q]) ans = max(ans, (ex(P[i-q]) + ex(Q[q]))%mod);
      else ans = max(ans, (ex(P[p]) + ex(Q[i-p]))%mod);
      cout << ans << (i == n-1 ? '\n':' ');
    }
  }
}


