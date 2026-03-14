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

ll K, M;

vl crr,lrr;

ll fe(ll b, ll e, ll m) {
  ll r = 1;
  while(e) {
    if(e&1) r*=b,r%=m;
    e>>=1;
    b*=b;b%=m;
  }
  return r;
}

ll pot11[] = {0, 1,11,111};
ll f11(ll n, ll m) {
  if (n<4) return pot11[n];
  ll x = f11(n/2,m);
  if (n&1) return ((x*10+1)*fe(10,n/2,m)+x)%m;
  else return (x*fe(10,n/2,m)+x)%m;
}

ll fn(ll m) {
  ll acc=0;
  ll ans = 0;
  for (auto i = 0; i < K; i++) {
    ans+=crr[i]*f11(lrr[i],m)*fe(10,acc,m)%m;
    ans%=m;
    acc+=lrr[i];
  }
  return ans;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  cin>>K>>M;
  crr.resize(K);
  lrr.resize(K);
  for (auto i = 0; i < K; i++) {
    cin>>crr[i]>>lrr[i];
  }
  reverse(all(crr));
  reverse(all(lrr));
  ll mod = 10007;
  // dbg(fn(mod));
  ll ans = (fn(mod)-fn(M)%mod+mod)%mod;
  ans*=fe(M,mod-2,mod);
  ans%=mod;
  cout<< (ans)<<'\n';
}

