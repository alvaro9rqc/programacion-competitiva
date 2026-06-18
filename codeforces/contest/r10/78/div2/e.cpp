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
  ll n, m;cin>>n>>m;
  ll inf=1e16;
  vector<vl>
    gri(n,vl(m)),
    rig(n,vl(m,inf)),
    dow(n,vl(m,inf)),
    dpg(n,vl(m)),
    gen(n,vl(m)),
    dpo(n,vl(m));
  for(auto& r: gri) for(auto& c: r) cin >> c;
  dpo[0][0]=gri[0][0];
  //dpo
  for (auto r = 1; r < n; r++) dpo[r][0]=gri[r][0]+dpo[r-1][0];
  for (auto c = 1; c < m; c++) dpo[0][c]=gri[0][c]+dpo[0][c-1];
  for (auto r = 1; r < n; r++) 
    for (auto c = 1; c < m; c++) 
      dpo[r][c]=max(dpo[r-1][c],dpo[r][c-1])+gri[r][c];
  //dpg
  dpg[n-1][m-1]=gri[n-1][m-1];
  for (auto r = n-2; r >=0; r--) dpg[r][m-1]=dpg[r+1][m-1];
  for (auto c = m-2; c >=0; c--) dpg[n-1][c]=dpg[n-1][c+1];
  for (auto r = n-2; r >=0; r--)
    for (auto c = m-2; c >=0; c--) 
      dpg[r][c]=max(dpg[r+1][c],dpg[r][c+1])+gri[r][c];
  //gen
  for (auto r = 0; r < n; r++) 
    for (auto c = 0; c < m; c++) 
      gen[r][c]=dpo[r][c]+dpg[r][c]-gri[r][c];
  //acc
  for (auto r = 0; r < n; r++) 
    for (auto c = 0; c < m; c++) {
      rig[r][c]=c?( gen[r][c-1] ):( gen[r][c]);
      dow[r][c]=r?( gen[r-1][c] ):( gen[r][c]);
    }
  ll ans = inf;
  //esq
  ans=min(ans,dpg[0][0]-2*gri[0][0]);
  ans=min(ans,dpo[n-1][m-1]-2*gri[n-1][m-1]);
  //lad
  for (auto r = 1; r < n; r++) 
    if(m>=2){
      ans=min(ans,max(dow[r-1][1],gen[r][0]-2*gri[r][0]));
    }else {
      ans=min(ans,gen[r][0]-2*gri[r][0]);
    }
  for (auto c = 0; c < m-1; c++) 
    if(n>=2) {
      ans=min(ans,max(dow[n-2][c+1],gen[n-1][c]-2*gri[n-1][c]));
    }else{
      ans=min(ans,gen[n-1][c]-2*gri[n-1][c]);
    }
  for (auto r = 0; r < n-1; r++) 
    if(m>=2) {
      ans=min(ans,max(rig[r+1][m-2],gen[r][m-1]-2*gri[r][m-1]));
    }else{
      ans=min(ans,gen[r][m-1]-2*gri[r][m-1]);
    }
  for (auto c = 1; c < m; c++) 
    if(n>=2) {
      ans=min(ans,max(rig[1][c-1],gen[0][c]-2*gri[0][c]));
    }else{
      ans=min(ans,gen[0][c]-2*gri[0][c]);
    }
  //gen
  for (auto r = 1; r < n-1; r++) 
    for (auto c = 1; c < m-1; c++) 
      ans=min(
        ans,
        max({
          dow[r-1][c+1],
          rig[r+1][c-1],
          gen[r][c]-2*gri[r][c]
        })
      );
  cout<<ans<<'\n';
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

