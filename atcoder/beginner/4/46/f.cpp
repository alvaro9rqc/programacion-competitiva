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
  int n,m;cin>>n>>m;
  vector<vi>adj(n+1);
  for (auto i = 0; i < m; i++) {
    int x,y;cin>>x>>y;
    adj[x].emplace_back(y);
  }
  set<int>A,B;
  B.emplace(1);
  for (auto i = 1; i < n+1; i++) {
    queue<int> que;
    if (B.count(i)) {
      B.erase(i);
      A.emplace(i);
      que.emplace(i);
    }
    while(sz(que)) {
      int u = que.front(); que.pop();
      for(auto& v: adj[u]) {
        if (v<i) {
          if (not A.count(v)) {
            A.emplace(v);
            que.emplace(v);
          }
        } else if (v>i) {
          B.emplace(v);
        }
      }
    }
    ///
    // for(auto& u: A) cout<<u<<' ';
    // raya;
    cout<<(sz(A)==i?sz(B):-1)<<'\n';
  }
}

