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
    int mi = n+1,ma=0;
    vi lef(n+1,n),rig(n+1,0);
    vi val(n); for(auto& i: val) {
      cin >> i,mi=min(mi,i),ma=max(ma,i); 
    }
    for (auto i = 0; i < n; i++) {
      lef[val[i]]=min(lef[val[i]],i);
      rig[val[i]]=max(i,rig[val[i]]);
    }
    for (auto i = mi+1; i <= n; i++) {
      lef[i]=min(lef[i],lef[i-1]);
      rig[i]=max(rig[i],rig[i-1]);
    }
    bool can = 1;
    for (auto t = mi; t < ma+1; t++) {
      int l = rig[t]-lef[t]+1;
      if(l>t) {can=0;break;}
    }
    mi = n,ma=0;
    vi s(n);
    for (auto i = 0; i < n; i++) {
      ++s[max(0,i-val[i]+1)];
      if(i+val[i]<n)--s[i+val[i]];
    }
    for (auto i = 0,xd=0; i < n; i++) {
      xd+=s[i];
      if(xd==n) mi=min(i,mi),ma=max(i,ma);
    }
    cout<<can*(ma-mi+1)<<'\n';
  }
}

