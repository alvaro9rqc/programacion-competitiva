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

ll pot(ll b, ll e) {
  ll ans = 1;
  for (ll i = 0; i < e; ++i) ans*=b;
  return ans;
}

ll mon(ll x) {
  return ll(pot(3,x+1) + x*pot(3, x-1));
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt; cin >> tt;
  while(tt--) {
    ll n; cin >> n;
    ll k; cin >> k;
    ll ans = 0;
    vl re(19);
    vl es(19), cs(19);
    for (auto i = 0ll; i < 19; ++i) {
      es[i] = pot(3,i);
      cs[i] = mon(i);
    }
    while(n) {
      ll ex = (ll)(log(n) / log(3));
      //dbg(ex);
      //dbg(mon(ex));
      if (n >= pot(3, ex+1)) ++ex;
      re[ex]++;
      //if (sz(re) and es.back() == ex) {
      //  re.back()++;
      //} else {
      //  re.emplace_back(1);
      //  es.emplace_back(ex);
      //  cs.emplace_back(mon(ex));
      //}
      n -= (ll)(pot(3,ex));
      ans+=mon(ex);
      --k;
    }
    if (k < 0) {cout << -1 << '\n'; continue;}
    //for(auto& e: re) cout << e<<' '; 
    //cout << '\n';
    //for(auto& e: es) cout << e<<' '; 
    //cout << '\n';
    //for(auto& e: cs) cout << e<<' '; 
    //cout << '\n';
    for (auto i = sz(re)-1; i > 0; --i){
      ll sus = es[i] / es[i-1]-1;
      ll rep = min(k / sus, re[i]);
      re[i] -= rep;
      re[i-1] += (sus+1)*rep;
      k -= sus*rep;
    }
    //for(auto& e: re) cout << e<<' '; 
    //cout << '\n';
    //for(auto& e: es) cout << e<<' '; 
    //cout << '\n';
    //for(auto& e: cs) cout << e<<' '; 
    //cout << '\n';
    //raya;
    ans = 0;
    for (auto i = 0; i < sz(re); ++i) ans+= re[i]*cs[i];
    cout << ans <<'\n';
    //raya;
  }
}


