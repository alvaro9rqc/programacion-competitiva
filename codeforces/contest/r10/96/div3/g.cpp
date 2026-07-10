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

#include <bits/extc++.h>
using namespace __gnu_pbds;
template<class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag,
tree_order_statistics_node_update>;

void solve() {
  int n;cin>>n;
  vl val(n);
  for(auto& i: val) cin>>i;
  auto f=[&](int ini) {
    Tree<pair<ll,int>> ost;
    vl v={0, val[ini]};
    for (auto i = ini+2; i < n; i+=2) 
      v.emplace_back(-val[i-1]),
      v.emplace_back(val[i]);
    for (auto i = 1; i < sz(v); i++) 
      v[i]+=v[i-1];
    // for(auto& xd: v) cout<<xd<<' ';
    // cout<<'\n';
    ll ans = 0;
    for (auto i = sz(v)-2; i >= 0; i-=2) {
      // dbg(v[i]);
      ost.insert({v[i+1],i+1});
      auto j = ost.order_of_key({v[i]+1,0});
      ans+=sz(ost)-j;
      // dbg(sz(ost)-j);
    }
    return ans;
  };
  ll ans = f(0);
  if(n>1)ans+=f(1);
  cout<<ans<<'\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt=1;
  cin>>tt;
  while(tt--) {
    solve();
  }
}

