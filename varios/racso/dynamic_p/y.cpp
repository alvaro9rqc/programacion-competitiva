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

vector<ii> E;
vl fac;
vl invfac;
//ll mod =13;// 
ll mod = ll(1e9+7);
vl memo;

ll comb(ll n, ll b) {
  //cerr << n << ' ' << b << '\n';
  if (b == 0 or n == b) return 1;
  //return(fac[n] / (fac[b]*fac[n-b]));
  //ll ans = fac[n]*invfac[b]%mod;
  ll ans = fac[n]*invfac[b]%mod*invfac[n-b]%mod;
  //cout << n << ' '<<b<<' '<<ans<<'\n';
  return ans;
  //return ans*invfac[n-b]%mod;
}

ll dp(int i) {
  if (memo[i] != -1) return memo[i];
  auto [r, c] = E[i];
  ll ans = comb(r-1 + c-1, r-1);
  //cerr << i << ':' << ans << '\n';
  for (auto j = 0; j < sz(E); ++j) {
    auto& [r1, c1] = E[j];
    if (i != j and r1 <= r and c1 <= c) {
      ans = (ans-dp(j)*comb(r-r1+c-c1, r-r1)%mod)%mod;
      ans = (mod + ans)%mod;
    }
  }
  //cerr << i << ' ' << ans << '\n';
  return memo[i] = ans;
}

inline ll fae(ll b, ll e) {
  ll ans = 1;
  //cout << b << ' ' << e << '\n';
  while(e) {
    if (e&1) ans = ans*b%mod;
    e >>=1;
    b = b*b%mod;
  }
  //cout << ans << '\n';
  return ans;
}

void load(ll n){
  invfac.resize(n+1);
  fac.resize(n+1);
  fac[0] = 1;
  for (ll i = 1; i <= n; ++i) {
    fac[i] = fac[i-1]*i%mod;
    //invfac[i] = fae(fac[i], mod-2);
    //cout << invfac[i] << '\n';
  }
  invfac[n] = fae(fac[n], mod-2);
  for (auto i = n-1; i >= 0; --i) 
    invfac[i] = invfac[i+1] * (i+1)%mod;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
int h,w, n;
  cin >> h >> w >> n;
  E.resize(n+1);
  memo.assign(n+1,-1);
  E.back() = {h,w};
  load(h+w);
  for (auto i = 0; i < n; ++i) {
    int a, b; cin >> a >> b;
    E[i] = {a,b};
  }
  //for(auto& [a,b]: E) cin >> a >> b;
  cout << dp(n) << '\n';
}


