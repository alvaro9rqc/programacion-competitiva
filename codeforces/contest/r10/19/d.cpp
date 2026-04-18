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
    auto f=[&](vi& v, bool rigth, int lev) {
      int del = rigth?1:-1;
      for (auto i = rigth?0:sz(v)-1; (rigth?(i<sz(v)):i>=0); i+=del) {
        if(lev&1) {
          ans[v[i]]=deq.back(); deq.pop_back();
        } else {
          ans[v[i]]=deq.front(); deq.pop_front();
        }
      }
    };
    for (auto i = 1; i <= ma; i++) {
      vector<vi> comp;
      int lat=0;
      int xd = 0;
      for (auto j = 0; j < n; j++) {
        if(val[j]>i or val[j]==-1) xd=j,lat=0;
        if(val[j]!=i)
          continue;
        if(lat)comp.back().emplace_back(j);
        else comp.emplace_back(1,j);
        lat=1;
      }
      for(auto& v: comp) {
        f(v,v.back()<xd,i);
      }
    }
    for (auto i = 0; i < n; i++) 
      if(val[i]==-1) ans[i]=deq.front();
    for(auto& i: ans) cout<<i<<' ';
    cout<<'\n';
  }
}

