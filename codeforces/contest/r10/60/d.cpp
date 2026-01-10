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
    int n; cin >> n;
    vector<vi> adj(n);
    for (auto i = 0; i < n-1; i++) {
      int x, y; cin>> x >>y;
      --x,--y;
      adj[x].emplace_back(y);
      adj[y].emplace_back(x);
    }
    vector<vi>lev;
    vector<bool>vis(n);
    vis[n-1]=1;
    queue<int> que;
    que.emplace(n-1);
    int ori = -1;
    while(sz(que)) {
      lev.emplace_back();
      int s = sz(que);
      for (auto i = 0; i < s; i++) {
        int u = que.front();
        que.pop();
        lev.back().emplace_back(u);
        if (u == 0) ori = sz(lev)-1;
        for(auto& v: adj[u]) 
          if (not vis[v]) que.emplace(v), vis[v]=1;
      }
    }
    vi ans;
    auto f = [&](int x, int i) {
      if (x == -1) {
        if (ori == i) ori--;
        else ++ori;
        ans.emplace_back(-1);
      } else {
        ans.emplace_back(x);
      }
    };
    for (auto i = sz(lev)-1; i > 0; i--) {
      for (auto j = 0; j < sz(lev[i]); j++) {
        if (ori==i) f(-1, i);
        f(lev[i][j], i);
        f(-1,i-(j==sz(lev[i])-1));
        //dbg(ori);
        //dbg(i);
      }
    }
    cout << sz(ans)<<'\n';
    for(auto& i: ans) {
      if (i==-1) cout << "1 \n";
      else cout << "2 " << i+1 <<'\n';
    }
  }
}

