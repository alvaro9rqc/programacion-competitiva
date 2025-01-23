#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;

typedef pair<ll, ll> ll_p; 
typedef tuple<ll, ll, ll> ll_t; 
typedef vector<ll> vll;
typedef vector<ll_p> vll_p;   
typedef vector<ll_t> vll_t;

vector<vi> g;

int mv() {
  int a = 0;
  int s=g[0].size();
  int d = 0;
  for(auto& v: g[0]) {
    d += g[v].size();
  }
  for (auto i = 0; i < g.size(); ++i) {
    if (g[i].size() > s) {
      s = g[i].size();
      a = i;
      d = 0;
      for(auto& v: g[i]) {
        d += g[v].size();
      }
    } else if(g[i].size() == s) {
      int d2 = 0;
      for(auto& v: g[i]) {
        d2 += g[v].size();
      }
      if (d2 < d) {
        s = g[i].size();
        a = i;
        d = d2;
      }
    }
  }
  return a;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >>t;
  while (t--) {
    int n; cin >> n;
    g.assign(n, vi());
    for (auto i = 0; i < n-1; ++i) {
      int u, v; cin >> u >> v;
      v--;u--;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    int v = mv();
    int ans = g[v].size();
    for(auto& u: g[v]) {
      g[u].erase(find(g[u].begin(),g[u].end(), v));
    }
    g[v].clear();
    v = mv();
    ans += g[v].size()-1;
    cout << ans << '\n';
  }
  return 0;
}


