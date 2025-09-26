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
  using pll = pair<ll,ll>;
  ll n, m; cin >> n >> m;
  vector<pll> pares;
  vl ids(n-1);
  iota(ids.begin(), ids.end(), 0ll);

  ll a, b; cin >> a >> b;
  for (ll i = 1; i < n; ++i) {
    ll x, y; cin >> x >> y;
    pares.emplace_back(x-b+1, y-a+1);
    a = x, b = y;
  }
  vl br(m); //tipos de puentes
  for(auto& e: br) cin >> e;
  sort(ids.begin(), ids.end(), [&pares, &ids](int gaa2, int gaa1) {
      return pares[gaa2] <= pares[gaa1];
      });
  vl id_p(m);
  iota(id_p.begin(), id_p.end(), 0ll);
  sort(id_p.begin(), id_p.end(), [&br](ll x1, ll x2){
      return br[x1] <= br[x2];
      });
  
  sort(br.begin(), br.end());
  vl ans(n-1, -1);
  ll taken = 0;
  ll idx = 0;
  multimap<ll,ll> mm;


  for(auto& idx_p: id_p) {
    //añadir trechos disponibles
    while (idx < n-1 and br[idx_p] >= pares[ids[idx]].first )
    {
        mm.insert({pares[ids[idx]].second, ids[idx]});
        cout << "->" <<pares[ids[idx]].second <<'\n';
      ++idx;
    }
    //ver si existe algún trecho para este puente
    while(mm.size()) {
      auto it = mm.begin();
      if (br[idx_p] <= it->first) {
        cout << "ga: " << it->first <<" " << it->first <<'\n';
        cout << "t: " << taken << '\n';
        ans[it->second] = idx_p;
        mm.erase(it);
        ++taken;
        break;
      } else { mm.erase(it->first) ;}
    }
  }
  if (taken >= n-1) {
    cout << "Yes\n";
    for(auto& e: ans ) cout << e <<' ';
    cout <<'\n';
  } else {
    cout << "No\n";
  }
}


