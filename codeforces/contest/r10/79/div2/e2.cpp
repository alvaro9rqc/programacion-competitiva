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
    ll ans = 0;
    int n;cin>>n;
    vector<vi> mtx(n, vi(n));
    vl dp(n);
    ll k = 1;
    while(1) {
      ++k;cout<<"? "<<k<<endl;
      ll q;cin>>q;
      if(!q) break;
      vi nds(q); for(auto& i: nds) cin >> i,--i;      
      // if(q==1 and nds.back()==n-1)break;
      ll d = dp[ nds.back() ];
      // dbg(d);
      // dbg(nds.back());
      for (auto i = sz(nds)-2; i>=0; i--) {
        if(!mtx[nds[i]][nds[i+1]]) ++ans, mtx[nds[i]][nds[i+1]]=1;
        dp[nds[i]]+=1+d;
      }
      k+=d;
    }
    cout<<"! "<<ans<<endl;
    for (auto i = 0; i < n; i++) {
      for (auto j = 0; j < n; j++) if(mtx[i][j]) cout<<i+1<<" "<<j+1<<endl;
    }
  }
}

