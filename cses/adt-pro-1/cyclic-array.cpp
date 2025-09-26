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
  int n;
  ll k; cin >> n >> k;
  ll lim = 61;
  vl arr(n); 
  for(auto& i: arr) cin >> i;
  ll sum = 0;
  vector<vi> tel(lim, vi(n));
  vector<vl> siz(lim, vl(n));
  for (int i = 0,j=0; i < n; i++) {
    while(sum + arr[j]<=k) {
      sum+=arr[j], ++j, j%=n; 
      if (j == i) {
        break;
      }
    }
    tel[0][i] = j;
    if (j == i) siz[0][i] = sum+arr[j]<=k?n+1:n;
    else siz[0][i] = ((j - i + n)%n);
    sum-= arr[i];
  }
  for (auto lev = 1; lev < lim; lev++) {
    for (auto i = 0; i < n; i++) {
      if (siz[lev-1][i]<=n) {
        tel[lev][i] = tel[lev-1][tel[lev-1][i]];
        siz[lev][i] = siz[lev-1][i]+siz[lev-1][tel[lev-1][i]];
      } else {
        tel[lev][i] = tel[lev-1][i];
        siz[lev][i] = siz[lev-1][i];
      }
    }
  }
  //for(auto& i: tel[3]) cout <<i<<' '; cout <<'\n';
  //for(auto& i: siz[3]) cout <<i<<' '; cout <<'\n';
  ll ans = n;
  for (auto i = 0; i < n; i++) {
    ll lans = 0;
    ll d = 0;
    int v = i;
    for (auto l = lim-1; l >= 0; l--) {
      if (d+siz[l][v]<=n) lans+=1<<(l),  d+=siz[l][v], v = tel[l][v];
    }
    //dbg(i);
    //dbg(lans);
    //raya;
    ans=min(ans, lans+(d!=n));
  }
  cout << ans <<'\n';
}


