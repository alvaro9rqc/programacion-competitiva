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
  int n;cin>>n;
  vl val(n);
  for(auto& i: val) cin >> i; 
  vl pf(n+1), ss(n);
  for (auto i = 1; i < n; i++) pf[i]=abs(val[i-1])+pf[i-1];
  for (auto i = n-2; i >= 0; i--) ss[i]=val[i+1]+ss[i+1];
  ll idx = -1;
  ll s = -(1e17);
  for (auto i = n-1; i >= 0; i--) {
    if(val[i]>0) {
      ll xd = -val[i]+ss[i]+pf[i];
      if(xd>s)s=xd,idx=i;
    }
  }
  if(idx==-1 or (ss[0]+val[0]>=s)) {
    cout<<"0\n\n";return;
  }
  // dbg(s);
  vl res;
  bool inv=0;
  for (auto i = idx-1; i >=0; i--) {
    if(val[i]>0 and inv==0) res.emplace_back(i+1),inv=1;
    else if(val[i]<0 and inv==1) res.emplace_back(i+1),inv=0;
  }
  res.emplace_back(idx+1);
  cout<<sz(res)<<'\n';
  for(auto& v: res) cout<<v<<' ';
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

/*

+2 +10 +11 +3 +10 +15 -7 +18 +16 +17 -9

*/
