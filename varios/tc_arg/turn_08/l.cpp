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
  int tt; cin >> tt; 
  while(tt--) {
    int n, m; cin >> n >> m;
    vl bat(n), cap(n);
    list<ll> prio;
    vector<bool> used(n,0);
    list<pair<ll,ll>> term(m);
    for(auto i = 0; i < n; ++i) {
      cin >> bat[i];
      cap[i] = bat[i];
    }
    for(ll i = 0; i < m; ++i) {
      ll x, nb; cin >> x >> nb;
      --nb;
      term.emplace_back(x,nb);
      used[nb] = 1;
      prio.emplace_back(nb);
    }
    for(ll i = 0; i< n; ++i) 
      if (not used[i]) prio.emplace_back(i);
    ll ans = 0;
    while(prio.size() and term.size()) {
      auto b = prio.front();
      auto[x, nb] = term.front();
      if (ans + cap[b] < x) {
        prio.pop_front();
        ans += cap[b];
        cap[b] = 0;
      } else {
        term.pop_front();
        if (b == nb) {
          prio.pop_front();
          cap[b] = bat[b];
          prio.emplace_back(b);
        } else {
          cap[b] -= x - ans;
          cap[nb] = bat[nb];
          prio.emplace_back(nb);
        }
        ans = x;
      }
    }
    for(auto& c: cap) ans += c;
    cout << ans <<'\n';
  }
}


