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
    ll r,l;cin>>r>>l;
    ll t = r+2*l;
    ll n = 1;
    ll m = 2*t;
    for (auto i = 1; i*i <= t ; i++) {
      if( (t-i) % (i*2+1)==0) {
        ll np = i;
        ll mp = (t-np) / (np*2+1);
        if(mp-np>=0 and mp-np<=m-n) n=np,m=mp;
      }
    }
    if(l<=(t-(m-n))/2) {
      cout<< n <<' '<<m<<'\n';
    } else cout<<"-1 \n";
  }
}

