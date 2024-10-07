#include <bits/stdc++.h> 
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main () {
  ios_base::sync_with_stdio(false);
  int m, n;
  cin >> m;
  while (m--) {
    cin >> n;
    vector<unordered_set<int>> g(n, unordered_set<int>());
    for (int i = 0; i < n; ++i) {
      int j;
      cin >> j;
      for (int k = 0; k < j; ++k) {
        int l; cin >> l; --l;
        if (l >= n) continue;
        g[i].insert(l);
        g[l].insert(i);
      }
    }
    //cout << n << '\n';
    vi visi(n, 10);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      if (visi[i] == 10) {
        int count = 1;
        int nodes = 0;
        visi[i] = 0;
        queue<int> q; q.push(i);
        bool isBi = true;
        while (! q.empty()){
          nodes++;
          int u = q.front(); q.pop();
          for (auto& v : g[u]) {
            if (visi[v] == 10) {
              visi[v] = 1 - visi[u];
              q.push(v);
              if (visi[v] == 0) count++;
            } else if (visi[v] == visi[u]) isBi = false;
          }
        }
        int ad =max(count, nodes - count); 
        if (!isBi) ad = 0;
        ans += ad;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}


