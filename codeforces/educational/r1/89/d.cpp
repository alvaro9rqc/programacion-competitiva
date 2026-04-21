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
ll mod=998244353;
ll n;
ll fr(ll x) {
  return ((n-(x-1))/4)%mod;
}
ll fl(ll x) {
  return (x/4+1)%mod;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt;cin>>tt;
  while(tt--) {
    ll x;
    cin>>n>>x;
    ll ans =0;
    if(x&1) {
      ans=fl(x-1)*fr(x-1);
      ans%=mod;
      if(x>1) ans+=fl(x-3)*fr(x-3);
      ans%=mod;
    } else {
      ans=fl(x)*fr(x);
      ans%=mod;
      ans+=fl(x-2)*fr(x-2);
      ans%=mod;
    }
    cout<<ans<<'\n';
  }
}

