#include <bits/stdc++.h>
#include <bits/extc++.h>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
#define dbg(x) cerr << #x << " = " << (x) << endl;
#define raya cerr << " ==================== " << endl;
#define rep(i, a, b) for (auto i = a; i < (b); ++i)
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)


#include <bits/extc++.h>
// To use most b i t s rather than j u s t the lowest ones :
struct chash { // large odd number for C
  uint64_t C = ll(4e18 * acos(0)) | 71;
  ll operator()(ll x) const { return __builtin_bswap64(x*C); }
};
// __gnu_pbds::gp_hash_table<ll,int,chash> h({},{},{},{},{1<<16});
using h_m = __gnu_pbds::gp_hash_table<ll,ll,chash>;

void solve() {
  ll m;
  auto f=[&](vl& v)->pair<h_m,h_m> {
    int n= sz(v);
    h_m p2,p1;
    p2[0]=p1[0]=1;
    for (auto i = 0; i < n; i++) {
      vector<pair<ll,ll>> cp;
      for(auto& [s,r]: p2) cp.emplace_back((s+v[i])%m,r);
      p2=p1;
      for(auto& [s,r]: cp) p1[s]+=r;
    }
    return {p2,p1};
  };
  ll n;cin>>n>>m;
  if(n<10) {
    vl val(n); for(auto& v: val) cin>>v;
    auto[p2,p1]=f(val);
    cout<<p1[0]<<'\n';
    return ;
  }
  ll lim = n/2;
  vl v1(lim),v2(n-lim-1);
  ll xd;
  for(auto& i: v1) cin >> i;
  cin>>xd;
  for(auto& i: v2) cin >> i;
  reverse(all(v2));
  auto [p2,p1]=f(v1);
  auto [s2,s1]=f(v2);
  ll ans = 0;
  for(auto& [s,r]: p1) {
    auto it = s1.find((m-s)%m);
    if(it!=s1.end()) ans+=(r*it->second);
  }
  for(auto& [s,r]: p2) {
    auto it = s2.find( (m-(xd+s)%m)%m);
    if(it!=s2.end()) ans+=(r*it->second);
  }
  cout<<ans<<'\n';
}


int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  solve();
}

