#include <bits/stdc++.h> 
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int step;
vector<vi> dfs_num;
unordered_map<char, ii> m =  {
  {'S', {1,0}},
  {'E', {0, 1}},
  {'W', {0, -1}},
  {'N', {-1,0}}
};

int cycleCheck(vector<string>& g, int r, int c) {
  if ( (r < 0) || (r >= g.size()) ) return -1;
  if ( (c < 0) || (c >= g[0].size()) ) return -1;
  ++step;
  if (dfs_num[r][c] != -1) return step - dfs_num[r][c];
  dfs_num[r][c] = step;
  //cout << r<<' '<<c<<'\n';
  return cycleCheck(g, r + m[ g[r][c] ].first, c + m[ g[r][c] ].second );
  
}

int main () {
  ios_base::sync_with_stdio(false);
  int h, w, s;
  while (cin >> h >> w >> s) {
    if ( 
        h == 0 &&
        w == 0  &&
        s == 0
       ) break;
    step = 0;
    //cout << h << ' ' <<w<<' '<<s<<'\n';
    --s; //check
    vector<string> g(h);
    cin >> ws;
    for (int i = 0; i<h; ++i) getline(cin, g[i]);
    dfs_num.assign(h, vi(w, -1));
    int r = cycleCheck(g, 0, s);
    if (r == -1)cout << step<<" step(s) to exit\n";
    else cout << step-r-1<<" step(s) before a loop of "<<r<<" step(s)\n";
  }
  return 0;
}


