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

int fb(int x) {
  return 31-__builtin_clz(x);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt;cin>>tt;
  while(tt--) {
    int n,q;cin>>n>>q;
    vi val(n);
    for(auto& i: val) cin >> i;
    reverse(all(val));
    vi r(n);
    for (auto i = 1; i < n; i++) r[i]=r[i-1]^val[i-1];
    int lim = 30;
    vector<vi> alc(lim, vi(n));
    for (auto i = 0; i < lim; i++) alc[i][n-1]=n;
    for (auto i = 0; i < lim; i++) {
      for (auto j = n-2; j >= 0; j--) 
        alc[i][j]=i>fb(val[j+1])?
           alc[i][j+1]:j+1;
    }
    for (auto _ = 0; _ < q; _++) {
      int x;cin>>x;
      int b = fb(x);
      int i=0;
      while(i!=n) {
        if((r[i]^x)<val[i])break;
        int xi = r[i]^x^val[i];
        if(not xi) {++i; break; }
        b=fb(xi);
        i=alc[b][i];
      }
      cout<<i<<' ';
    }
    cout<<'\n';
  }
}

