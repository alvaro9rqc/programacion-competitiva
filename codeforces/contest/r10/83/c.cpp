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
    vector<vi> tot;
    for (auto i = 0; i < n; i++) {
      set<ll> xd;
      int l;cin>>l;
      vi e(l);
      for(auto& j: e) cin>>j;
      tot.emplace_back();
      reverse(all(e));
      for(auto& j: e) {
        if (xd.count(j)) continue;
        xd.emplace(j);
        tot.back().emplace_back(j);
      }

      // for (auto j = 0; j < l; j++) {
      //   ll x;cin>>x;
      //   if (xd.count(x))continue;
      //   xd.emplace(x);
      //   tot.back().emplace_back(x);
      // }
      // reverse(all(tot.back()));
    }
    vi vis(n);
    int tk = 0;
    vi ans;
    set<int>ose;
    while(tk!=n) {
      int c=0;
      for (; c < n and vis[c]; c++);
      for (auto j = c+1; j < n; j++) {
        if (vis[j])continue;
        if (tot[j]<tot[c]) c=j;
      }
      vis[c]=1;
      ++tk;
      // for(auto& i: tot[c]) {
      //   cerr<<i<<" : ";
      // } 
      // cerr<<'\n';

      //tomamos
      for(auto& i: tot[c]) {
          ans.emplace_back(i);
          ose.emplace(i);
      }
      //update
      for (auto j = 0; j < n; j++) {
        if (vis[j])continue;
        vi v;
        for(auto& i: tot[j]) if(not ose.count(i))v.emplace_back(i);
        swap(v,tot[j]);
      }
    }
    for(auto& i: ans) cout<<i<<' ';
    cout<<'\n';
    // raya;
    // sort(all(tot));
    // set<int> ose;
    // vi ans;
    // for(auto& v: tot) {
    //   for(auto& i: v) {
    //     if (not ose.count(i)) {
    //       ans.emplace_back(i);
    //       ose.emplace(i);
    //     }
    //   }
    // }
    // for(auto& i: ans) cout<<i<<' ';
    // cout<<'\n';
  }
}

