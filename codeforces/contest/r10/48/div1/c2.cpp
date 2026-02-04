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
  while(tt--) {
    int n, ku,kl=0; cin >> n>>ku;
    vector<vi>son(n);
    for (auto i = 0; i < n-1; i++) {
      int x; cin >> x;
      son[x-1].emplace_back(i+1);
    }
    map<int,int> item;
    queue<int> que, xdd;
    que.emplace(0);
    int deep =0;
    while(sz(que)) {
      ++deep;
      int l = sz(que);
      kl+=l;
      item[l]++;
      bool fi = 0;
      for (auto i = 0; i < l; i++) {
        int u = que.front(); que.pop();
        for(auto& v: son[u]) que.emplace(v);
        if (not sz(son[u])) fi=1;
      }
      if (fi) que.swap(xdd);
    }
    kl=max(0, ku-(n-kl));
    vector<bool>dp(ku+1);
    dp[0]=1;
    for(auto& [c,r]: item) {
      vi used(ku+1);
      for (auto j = c; j < ku+1; j++) {
        if(not dp[j] and dp[j-c] and used[j-c]<r) {
          dp[j]=1;
          used[j]=used[j-c]+1;
        }
      }
    }
    bool can = 0;
    for (auto i = kl; i < ku+1; i++) 
      can|=dp[i];
    cout<< (can?deep:deep-1)<<'\n';
  }
}

