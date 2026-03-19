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

// To use most b i t s rather than j u s t the lowest ones :
struct chash { // large odd number for C
  uint64_t C = ll(4e18 * acos(0)) | 71+ chrono::steady_clock::now().time_since_epoch().count();
  ll operator()(ll x) const { return __builtin_bswap64(x*C); }
};
// __gnu_pbds::gp_hash_table<ll,int,chash> h({},{},{},{},{1<<16});
using h_m = __gnu_pbds::gp_hash_table<ll,ll,chash>;

int n; 
ll m;
vector<h_m> memo;
vl val;

ll dp(ll s, int i) {
  if(i>=n) return s==0;
  if(memo[i].find(s) != memo[i].end()) return memo[i][s];
  ll ans=0;
  ans+=dp(s,i+1);
  ans+=dp((s+val[i])%m,i+2);
  return memo[i][s]=ans;
}

pair<h_m, h_m> dp2(vl& v) {
  h_m pen, ult;
  pen[0]=1;
  ult[0]=1;
  ult[v[0]]+=1;
  for (auto i = 1; i < sz(v); i++) {
    h_m now=ult;
    for(auto& [s,r]: pen) 
    now[(s+v[i])%m]+=r;
    swap(pen,ult);
    ult=now;
  }
  return {pen,ult};
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  cin>>n>>m;
  val.resize(n);
  for(auto& i: val) cin>>i;
  if(n<10) {
    memo.assign(n,h_m());
    cout<<dp(0,0)<<'\n';
    return 0;
  }
  vl L(n/2), R(n-n/2);
  for (auto i = 0; i < n/2; i++) L[i]=val[i];
  for (auto i = n-1; i >= n-sz(R); i--) R[n-1-i]=val[i];
  auto[pl,ul]=dp2(L);
  auto[pr,ur]=dp2(R);
  ll ans = 0;
  for(auto& [s,r]: pl) 
  if(ur.find((m-s)%m) != ur.end())
    ans+=r*ur[(m-s)%m];
  for(auto [s,r]: ul) {
    if(pl.find(s) != pl.end()) r-=pl[s];
    if(pr.find((m-s)%m) != pr.end()) 
      ans+=r*pr[(m-s)%m];
  }
  cout<<ans<<'\n';
  return 0;
}

