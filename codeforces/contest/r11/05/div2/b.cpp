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

ll mod = 998244353;

ll f(ll b, ll e) {
  ll r=1;
  while(e) {
    if(e&1)r*=b,r%=mod;
    b*=b;b%=mod;
    e>>=1;
  }
  return r;
}

void solve() {
  ll n,m,r,c;cin>>n>>m>>r>>c;
  // dbg(n);
  // cout<<f(2,6)<<'\n';
  cout<<f(2, n*m-(n-r+1)*(m-c+1))<<'\n';
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

