#include <bits/stdc++.h>
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
  int n;cin>>n;
  h_m ap, op;
  for (auto i = 0; i < n; i++) {
    ll x;cin>>x;
    ll s=0;
    if(x==1){
      ap[1]++;
      ap[2]++;
      op[2]++;
      continue;
    }
    while(1) {
      ++ap[x];
      op[x]+=s;
      if(x==1) break;
      if(x&1)++x;
      else x>>=1;
      ++s;
    }
  }
  // dbg(op[2]);
  ll ans = 1e15;
  for(auto& [k,v]: ap) 
  if(v==n) ans=min(ans,op[k]);
  cout<<ans<<'\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt=1;
  cin>>tt;
  while(tt--) {
    solve();
  }
}

