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
  ll g1,g2;cin>>g1>>g2;
  auto f=[](ll n) {
    vl arr(n);
    for(auto& i: arr) cin>>i;
    ll r = 0;
    for (auto i = 0; i < n; i++) {
      if(i==n-1) r+=arr[i];
      else r+=arr[i]-arr[i+1]+1;
    }
    return r;
  };
  ll p1 = f(g1);
  ll p2 = f(g2);
  cout<<(p1>=p2?1:2)<<'\n';
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

