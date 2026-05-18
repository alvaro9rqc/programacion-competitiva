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
    int n;cin>>n;
    vl val(n);
    ll ans = 0;
    ll u = 0;
    ll ps=0,p=0;
    for(auto& x: val) {
      cin>>x;
      if(x==1) ++u;
      else {
        ps+=x/2-1;
        ++p;
        ans+=x;
      }
    }
    // dbg(p);
    if(p==1) ans+=min(u,ps+1);
    else ans+=min(ps,u);
    if(ans<3)ans=0;
    cout<<ans<<'\n';
  }
}

