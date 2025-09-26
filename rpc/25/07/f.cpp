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
  int n; ll c ; cin>>n >>c;
  vl arr(n*2);
  for (auto i = 0; i < n; i++) cin>>arr[i];
  for (auto i = n; i < 2*n; i++) arr[i]=arr[i-n];
  int lim = 20;
  vector<vi> bju(lim, vi(n*2+1,0));
  ll xd = 0;
  for (auto i = 0,j=0; i < n*2+1; i++) {
    while(j<2*n and xd<c) xd+=arr[j], ++j;
    if (j == i) xd+=arr[j],++j;
    bju[0][i]=j;
    xd-=arr[i];
  }
  bju[0][n*2]=n*2;
  //for(auto& i: bju[0]) cout << i <<' ';
  //cout <<'\n';
  for (auto lev = 1; lev < lim; lev++) {
    for (auto i = 0; i < n*2+1; i++) {
      bju[lev][i] = bju[lev-1][ bju[lev-1][i]];
    }
  }
  for (auto i = 0; i < n; i++) {
    int u = i, v = i+n;
    int ans = 0;
    for (auto lev = lim-1; lev >= 0; lev--) 
      if (bju[lev][u]<v) ans+=1<<lev, u = bju[lev][u];
    cout <<ans <<(i==n-1?'\n':' ');
  }
}

