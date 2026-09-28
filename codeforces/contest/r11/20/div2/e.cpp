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

ll lim = 2e5+3;
vl fac(lim,1);
ll mod = 1e9+7;
 void previo() {
  for (auto i = 2ll; i < lim; i++) 
    fac[i]=i*fac[i-1]%mod;
}

void solve() {
  ll n;cin>>n;
  vl arr(n);
  for(auto& i: arr) cin >> i; 
  ll m=(n-2)/2+(n&1);
  set<ll> ost;
  for (auto i = 0; i < m; i++) {
    // if(arr[i+1]+arr[n-2-i]!=arr[n-1]) {can=0;break;}
    ost.emplace(arr[i+1]);
    ost.emplace(arr[n-2-i]);
  }
  // if(n&1) {cout<<"0\n";return;}
  ll can = 1;
  ll ans = 0;
  for (auto i = 0; i < m+1 - (n&1); i++) {
    ll v = arr[n-i-2];
    set<ll>tkn;
    can = 1;
    for (auto j = 1ll,a=arr[n-1]-v; j < m+1-(n&1); j++,a+=arr[n-1]-v) {
      if(arr[n-1]-a != a and ost.count(a) and tkn.count(a)==0 and ost.count(arr[n-1]-a) and tkn.count(arr[n-1]-a)==0) {
        //disp
        tkn.emplace(a);
        tkn.emplace(arr[n-1]-a);
      } else {can=0;break;}
    }
    if(can and n&1) {
      ll x = 0;
      for (auto j = 1; j < n; j++) 
        if(!tkn.count(arr[j])) {
          x=arr[j]; break;
        }
      can = (tkn.count(v-x));
    }
    if(can ){
      ans=(ans+fac[m+1 - (n&1)]*fac[m-1]%mod)%mod;
    }
  }
  cout<<ans<<'\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt=1;
  cin>>tt;
  previo();
  while(tt--) {
    solve();
  }
}

