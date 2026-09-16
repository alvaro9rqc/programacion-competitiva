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

void solve() {
  int n;cin>>n;
  vl arr(n); for(auto& i: arr) cin >> i;
  sort(all(arr));
  ll mod = 998244353;
  ll c=0,nr=1,sn=arr.back();
  for (auto i = n-2; i >= 0; i--) {
    c = ( (n-i-1)*c%mod+nr*(mod+sn-arr[i]*(n-i-1)%mod)%mod )%mod;
    nr = (n-i-1)*nr%mod;
    sn =(sn+arr[i])%mod;
  }
  cout<<c<<'\n';
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

