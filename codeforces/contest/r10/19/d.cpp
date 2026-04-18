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
    int ma=0;
    vi ans(n), val(n); for(auto& i: val) cin >> i,ma=max(ma,i);
    deque<int> deq;
    for (auto i = 1; i < n+1; i++) deq.emplace_back(i);
    auto p=[&](int i, int lev) {
      auto it=deq.begin();
      if(lev&1) it=--deq.end();
      ans[i]=*it;
      deq.erase(it);
    };
    for (auto i = 1; i <= ma; i++) {
      int l=0,r=n-1;
      bool left = 1;
      while(l<=r) {
        //left
        if(left) 
          while(left) {
            if(l<n and val[l]==i) p(l,i);
            else left=0;
            ++l;
          } 
        else 
          while(not left) {
            if(r>=0 and val[r]==i) p(r,i);
            else left=1;
            --r;
          }
      }
    }
    for (auto i = 0; i < n; i++) 
      if(val[i]==-1) p(i,i);
    for(auto& i: ans) cout<<i<<' ';
    cout<<'\n';
  }
}

