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

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt;cin>>tt;
  while(tt--) {
    ll n;cin>>n;
    vl arr(n), brr(n);
    for(auto& i: arr) cin >> i;
    for(auto& i: brr) cin >> i;
    ll ans = 0;
    for (ll i = 0; i < n; i++) {
      ll v = arr[i];
      if(i==0 and i+1<n) 
        v=gcd(arr[i],arr[i+1]);
      else if(i==n-1 and i-1>=0) 
        v=gcd(arr[i],arr[i-1]);
      else {
        auto x=gcd(arr[i],arr[i-1]);
        auto y=gcd(arr[i],arr[i+1]);
        v=lcm(x,y);
      }
      ans+=v!=arr[i];
    }
    cout<<ans<<'\n';
  }
}

