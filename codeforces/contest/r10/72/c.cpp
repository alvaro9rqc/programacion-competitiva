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
  int tt; cin >> tt;
  while(tt--){
    ll n, k;cin >> n >> k;
    set<ll> vis;
    vis.emplace(0);
    vis.emplace(n);
    int lev = 0;
    int f = -1;
    queue<ll>que;
    que.emplace(n);
    while(sz(que) and f==-1){
      int s = sz(que);
      for (auto i = 0; i < s; i++) {
        ll u = que.front();
        que.pop();
        if (u == k) {f=lev;break;}
        ll arr[2]={u>>1, u-(u>>1)};
        for(auto& v: arr) {
          if (!(vis.count(v)) and v >= k)
            vis.emplace(v), que.emplace(v);
        }
      }
      ++lev;
    }
    cout << f <<'\n';
  }
}

