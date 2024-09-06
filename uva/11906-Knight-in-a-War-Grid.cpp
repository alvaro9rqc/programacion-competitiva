#include <bits/stdc++.h> 
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main () {
  ios_base::sync_with_stdio(false);
  int t; 
  cin >> t;
  int cases = 0;
  while (cases++ < t) {
    int R, C,m,n, w;
    cin >> R >>C>>m>>n>>w;
    vector<string> g(R, string(C, '.'));
    for (int i = 0; i < w;++i){
      int x, y; cin >> x>>y;
      g[x][y] = 'w';
    }
    queue<ii> q;
    q.push({0,0});
    vi dr = {m, m,-m,-m,n,n,-n,-n};
    vi dc = {n,-n,n,-n,m,-m,m,-m};
    if (m == 0 || n == 0 || m == n) {
      if (m < n) swap(m, n);
      dr = { m,-m, n, -n };
      dc = { n,-n, -m, m };
    }
    int odd, even; even = odd = 0;
    while (! q.empty()) {
      auto [r, c] = q.front(); q.pop();
      g[r][c] = '*';
      int org = 0;
      for (int i = 0; i < dr.size(); ++i) {
        if ( (r+dr[i] < 0) || (r+dr[i] >= R) ) continue;
        if ( (c+dc[i] < 0) || (c+dc[i] >= C) ) continue;
        if (g[r+dr[i]][c+dc[i]] == '.') {
          q.push({r+dr[i], c+dc[i]});
          g[r+dr[i]][c+dc[i]] = '*';
        }
        if (g[r+dr[i]][c+dc[i]] != 'w') ++org;
      }
      if (org & 1) ++odd;
      else ++even;
      //cout << i << ' ' << j << '\n';
    }
    cout << "Case "<<cases<<": "<<even<<" "<<odd<<"\n";
    //cout << "Case "<<cases<<R<<' '<<C<<' '<<": "<<even<<" "<<odd<<"\n";
  }
  return 0;
}


