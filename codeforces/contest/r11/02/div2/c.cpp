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

using li=pair<ll,int>;

void solve() {
  ll n;cin>>n;
  vl xd(n); for(auto& i: xd) cin >> i;  
  for (auto i = 0; i < n; i++) {
    vl val;
    for (ll j = i,k=0; k < n; k++,j=(j+1)%n) 
      val.emplace_back(xd[j]);
    vl rrr(n),lrr(n);
    for (auto j = 1ll,v=val[0]; j < n; j++) {
      rrr[j]=v;
      v=max(v,val[j]);
    }
    for (auto j =n-1,v=val[n-1]; j >= 0; j--) {
      v=max(val[j],v);
      lrr[j]=v;
    }
    ll ans = 0;
    for (auto j = 0; j < n; j++) ans+=min(lrr[j],rrr[j]);
    cout<<ans<<' ';
  }
  cout<<'\n';
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

