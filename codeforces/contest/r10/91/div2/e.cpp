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
  auto fv=[](vi& p) {
    vi v(sz(p));
    for (auto i = sz(p)-1; i >= 0; i--) {
      for (auto j = sz(p)-1; j > i; j--) {
        if(p[i]<p[j])++v[i];
      }
    }
    return v;
  };
  while(tt--) {
    int n;cin>>n;
    vi p(n); for(auto& i: p) cin >> i;  
    vi val(n); for(auto& i: val) cin >> i;  
    vector<vector<bool>> mtc(n,vector<bool>(n));
    for (auto i = 0; i < n; i++) {
      for (auto j = i+1; j < n; j++) 
        if(p[j]>p[i])mtc[i][j-i]=1;
    }
    auto pv = fv(p);
    bool can=1;
    for (auto i = 0; i < n; i++) {
      if(pv[i]<val[i]) {
        cout<<"-1\n";
        can=0;
        break;
      }
    }
    // dbg(can);
    if(not can) continue;
    list<ii> lis={{1,0}};
    for (auto i = n-2; i >= 0; i--) {
      for(auto& [k,v]: lis) ++v;
      auto it=lis.end();
      int c = 0;
      int nk=sz(lis)+1;
      while(c!=val[i]){
        --it;
        it->first++;
        if(mtc[i][it->second])++c;
        --nk;
        if(it==lis.begin()) break;
      }
      if(c!=val[i]){can=0;break;}
      lis.emplace(it,nk,0);
    }
    vi ans(n);
    for(auto& [k,i]: lis) ans[i]=k;
    // auto qv=fv(ans);
    if(can) for(auto& i: ans) cout<<i<<' ';
    else cout<< -1;
    cout<<'\n';
    // raya;
  }
}

