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
  ll x, y;cin>>x>>y;
  ll yo = y;
  ll xo = x;
  for (auto i = 31; i >= 0; i--) {
    ll m = 1ll<<i;
    if(m&y) continue;
    ll r = m - ( (m-1)&y);
    if(r<=x) x-=r,y+=r;
  }
  ll op = 0;
  for (auto i = 0; i < 32; i++) {
    ll m=1ll<<i;
    if(y&m) {
      if ( (yo&m) == (xo&m) ) {
        op+=m;
        yo+=m;
        xo-=m;
      }
    } else {
      if ( (yo&m) or (xo&m) ) {
        op+=m;
        yo+=m;
        xo-=m;
      }
    }
  }
  cout<<y<<' '<<op<<'\n';
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

