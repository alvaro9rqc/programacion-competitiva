#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  while (t--) {
    int n,m; cin >> n >> m;
    vector<vector<ll>> g(n,vector<ll>(m));
    string path; cin >> path;
    vector<ll> rs(n);
    vector<ll> cs(m);
    for(int r = 0; r < n; ++r) {
      int i = 0;
      for(auto& e: g[r]) {
        cin >> e;
        cs[i++] += e; 
        rs[r]+=e;
      }
    }
    int r=0,c=0;
    for (auto i = 0; i < path.size(); ++i) {
      if ( path[i] == 'R' ) {
        g[r][c] = - cs[c];
        rs[r] += g[r][c];
        c++;
      } else {
        g[r][c] = - rs[r];
        cs[c]+= g[r][c];
        r++;
      }
    }
    if ( path.back() == 'R' ) {
      g[r][c] = - cs[c];
      rs[r] += g[r][c];
      c++;
    } else {
      g[r][c] = - rs[r];
      cs[c]+= g[r][c];
      r++;
    }
    for(auto& r: g) {
      for(auto& c: r) {
        cout << c << ' ';
      }
      cout << '\n';
    }
  }
  return 0;
}


