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
  int n,k;cin>>n>>k;
  vi arr(n); 
  for(auto& i: arr) cin>>i,i%=k;
  vi pmp(k);
  ++pmp[arr[0]];
  for (auto i = 1; i < n; i++) arr[i]=(arr[i]+arr[i-1])%k, ++pmp[arr[i]];
  int g = 0;
  ll ans=0;
  for (auto i = 0; i < n; i++) {
    ans+=pmp[g];
    --pmp[arr[i]];
    g=arr[i];
  }
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

