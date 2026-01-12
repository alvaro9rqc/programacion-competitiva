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

int c(int i, int m, int n) {
  int x = n&(~m);
  int ans = 0;
  if ((x|m)==n)++ans;
  x>>=i+1;
  return x+ans;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt; cin >> tt;
  while(tt--) {
    int n; cin >> n;
    int ans = 0;
    int pre = 0;
    vi lis;
    for (auto i = 1; i < n; i++) lis.emplace_back(i);
    while(sz(lis)){
      vi ym, nm;
      //ans|=1<<pre;
      int r = c(pre, ans|(1<<pre), n);
      int col = 0;
      for(auto& i: lis) {
        int x=0; 
        if (col!=r) {
          cout << "? " << i<<" "<<(1<<pre)<<endl;
          cin >> x;
        }
        if(x)++col,ym.emplace_back(i);
        else nm.emplace_back(i);
      }
      if (col==r) {
        lis=nm;
      } else {
        ans|=1<<pre;
        lis=ym;
      }
      dbg(r);
      dbg(col);
      dbg(pre);
      dbg(ans|(1<<pre));
      dbg(ans);
      raya;
      ++pre;
    }
    if(!ans)ans|=1<<pre;
    cout << "! " << (ans) << endl;
  }
}

