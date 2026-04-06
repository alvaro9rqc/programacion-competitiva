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
  while(tt--){
    ll n,k;cin>>n>>k;
    set<ll> ost; map<ll,bool>vis;
    for (auto i = 0; i < n; i++) {
      ll x;cin>>x;
      ost.emplace(x);
      vis[x]=0;
    }
    bool can = 1;
    vl ans;
    for(auto& i: ost) {
      if(vis[i])continue;
      ans.emplace_back(i);
      for (auto j = i; j <= k; j+=i) {
        auto it = vis.find(j);
        if(it==vis.end()) {can=0;break;}
        it->second=1;
      }
      if(not can) break;
    }
    if(can) {
      cout<<sz(ans)<<'\n';
      for(auto& i: ans) cout<<i<<' ';
    } else cout<< -1;
    cout<<'\n';
  }
}

