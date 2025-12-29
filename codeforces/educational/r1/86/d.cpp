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

ll fmod(ll a, ll m) {
  return ((a%m) + m) % m;
}

ll extEuclid(ll a, ll b, ll &x, ll &y) {
  ll xx = y = 0;
  ll yy = x = 1;
  while (b) {
    ll q = a/b;
    ll t = b; b = a%b; a = t;
    t = xx; xx = x-q*xx; x = t;
    t = yy; yy = y-q*yy; y = t;
  }
  return a;
}

ll modInverse(ll b, ll m) {
  ll x, y;
  ll d = extEuclid(b, m, x, y);
  if (d != 1) return -1;
  return fmod(x, m);
}

int lim = 54;
vl p(lim), pinv(lim);
ll mod =998244353; 

ll comb(ll n, ll r) {
  ll ans = p[n];
  ll c = pinv[r]*pinv[n-r]%mod;
  return ans*c%mod;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt; cin >> tt;
  p[0]=1;
  pinv[0]=modInverse(p[0],mod);
  for (auto i = 1; i < lim; i++) {
    p[i] = i*p[i-1]%mod;
    pinv[i] = modInverse(p[i], mod);
  }
  while(tt--) {
    int n; cin >> n;
    vl arr(n+1);
    ll steps = 0;
    for(auto& i: arr) cin>>i, steps+=i;
    ll iter = steps / n;
    bool can = 1;
    for (auto i = 1; i < n+1; i++) {
      if (arr[i]> iter) arr[i]-=iter;
      else {
        ll x = iter-arr[i];
        arr[i]=0;
        if (x>arr[0]) {can=0;break;}
        else arr[0]-=x;
      }
    }
    if (not can) {cout << "0\n"; continue;}
    ll s = steps%n;
    ll ones = 0;
    for (auto i = 1; i < n+1; i++) {
      if (arr[i]>0)++ones;
      if (arr[i]>1)can=0;
    }
    if (not can) {cout << "0\n"; continue;}
    if (ones > steps) {cout << "0\n"; continue;}
    ll ans = comb(s, ones);
    ll zer = n - ones;
    //dbg(s);
    //dbg(ans);
    //dbg(ones);
    ans=ans*p[ones]%mod;
    //ans=ans*p[zel]%mod;
    ans=ans*p[zer]%mod;
    cout << ans <<'\n';
  }
}

