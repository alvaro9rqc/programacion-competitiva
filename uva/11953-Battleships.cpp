#include <bits/stdc++.h> 
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int dr[] = {1, 0, 0,-1};
int dc[] = {0, 1,-1, 0};

void flood(vector<string>& g, int r, int c) {
  if ( (r<0) || (r>= g[0].size()) ) return;
  if ( (c<0) || (c>= g.size()) ) return;
  if (g[r][c] == '.') return;
  g[r][c] = '.';
  for (int i= 0; i <4;++i)
    flood(g, r+dr[i], c+dc[i]);
}

int main () {
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  int ncase = 0;
  while (ncase++ != t) {
    int n; cin >> n;
    cin.ignore();
    int numcc = 0;
    vector<string> g(n);
    for (int i =0; i<n; ++i) 
      getline(cin , g[i]);
    for (int i=0; i<n;++i)
      for(int j=0; j<n; ++j)
        if (g[i][j] == 'x' ) {
          ++numcc; flood(g, i, j);
        }
    cout << "Case " << ncase<<": "<< numcc << '\n';
  }
  return 0;
}


