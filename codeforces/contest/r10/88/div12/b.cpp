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
    ll x, y;cin>>x>>y;
    if(not(x) or not(y)) {
      ll ans = 0;
      for (auto i = 1; i < max(x,y)+1; i++) 
        ans+=(max(x,y)%i==0);
      cout<<ans<<'\n';
      for (auto i = 0; i < max(x,y); i++) cout<<(x?1:-1)<<' ';
      cout<<'\n';
    } else {
      ll ans = 0;
      ll ma = max(x,y)-min(x,y)-1;
      ll mi = 1;
      while(ma>=0){
        ans+=((ma--%mi++)==0);
      }
      if(ans==0)++ans;
      cout<<(ans)<<'\n';
      for (auto i = 0; i < x; i++) cout<<1<<' ';
      for (auto i = 0; i < y; i++) cout<< -1<<' ';
      cout<<'\n';
    }
  }
}

