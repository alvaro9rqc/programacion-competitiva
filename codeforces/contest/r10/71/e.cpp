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
  int tt; cin >> tt;
  while(tt--) {
    ll n,x,y;cin>>n>>x>>y;
    string win;cin>>win;
    vl prr(n); 
    ll sp=0;
    for(auto& i: prr) cin >> i,sp+=i;
    bool can=1;
    can&=x+y>=sp;
    ll min_a=0,min_b=0;
    ll cant1=0;
    for (auto i = 0; i < n; i++) {
      if(win[i]=='1') {
        cant1++;
        min_b+=prr[i]/2+1;
      } else min_a+=prr[i]/2+1;
    }
    can&=min_a<=x;
    can&=min_b<=y;
    if(cant1==n) {
      can&=x<=y-n;
    } else if (cant1==0) {
      can&=x-n>=y;
    } 
    cout<<(can?"YES":"NO")<<'\n';
  }
}

