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

struct xdd {
  int a, b;
  char ac, bc;
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt;cin>>tt;
  while(tt--) {
    int n;cin>>n;
    vector<vector<queue<int>>> mtx(
      3,vector<queue<int>>(
        3));
    char d[]={'w','i','n'};
    for (auto id = 1; id < n+1; id++) {
      string s;cin>>s;
      char r[]={0,0,0};
      for(auto& c: s) {
        if(c=='w')++r[0];
        if(c=='i')++r[1];
        if(c=='n')++r[2];
      }
      int ma=0;
      for (auto i = 0; i < 3; i++) if(r[ma]<r[i])
        ma=i;
      // dbg(ma);
      for (auto i = 0; i < 3; i++) 
        if(r[i]<1)mtx[i][ma].emplace(id);
    }
    vector<xdd> ans;
    auto f=[&](int r, int c, int rp, int cp) {
      while(sz(mtx[r][c]) and sz(mtx[rp][cp])) {
        ans.emplace_back(
          mtx[r][c].front(), 
          mtx[rp][cp].front(),
          d[c],
          d[cp]
        );
        mtx[r][c].pop(), 
          mtx[rp][cp].pop();
      }
    };
    f(1,0,0,1);
    f(2,0,0,2);
    f(2,1,1,2);
    if(sz(mtx[1][0])) {
      mtx[2][0]=mtx[2][1];
      f(1,0,2,1);
      f(2,0,0,2);
    } else if(sz(mtx[0][1])) {
      mtx[0][2]=mtx[0][1];
      f(0,1,1,2);
      f(2,0,0,2);
    }
    cout<<sz(ans)<<'\n';
    for(auto& [a,b,ca,cb]: ans) {
      cout<<format("{} {} {} {} \n", a, ca, b, cb);
    }
  }
}

