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

int g = 0;

template<class T>
struct SubMatrix {
  vector<vector<T>> p;
  SubMatrix(vector<string>& v) {
    int R = sz(v), C = sz(v[0]);
    p.assign(R+1, vector<T>(C+1));
    for (auto r = 0; r < R; r++) 
      for (auto c = 0; c < C; c++) {
        g+=(v[r][c]=='g');
        p[r+1][c+1] = (v[r][c]=='g') + p[r][c+1] + p[r+1][c] - p[r][c];
      }
  }
  T sum(int u, int l, int d, int r) {
    if(d>sz(p)-1) d = sz(p)-1;
    if(r>sz(p[0])-1) r = sz(p[0])-1;
    if (u<0)u=0;
    if(l<0)l=0;
    // dbg(u);
    // dbg(l);
    // dbg(d);
    // dbg(r);
    return p[d][r] - p[d][l] - p[u][r] + p[u][l];
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt;cin>>tt;
  while(tt--) {
    g = 0;
    int n,m,k;cin>>n>>m>>k;
    vector<string> gri(n);
    for (auto i = 0; i < n; i++) cin>>gri[i];
    SubMatrix<int> smt(gri);
    int ans = 1e8;
    for (auto r = 0; r < n; r++) 
      for (auto c = 0; c < m; c++) 
        if(gri[r][c]=='.') {
          ans=min(ans, smt.sum(r-k+1,c-k+1,r+k,c+k));
          // dbg(ans);
        }
    // dbg(smt.sum(0,0,2,2));
    cout<<g-ans<<'\n';
  }
}

