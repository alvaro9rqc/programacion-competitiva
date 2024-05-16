#include <bits/stdc++.h> 
using namespace std;

int dr[] = {1, 1, 1, 0, 0, -1, -1, -1};
int dc[] = {-1, 0, 1, -1, 1, 1, -1, 0};
void flodd (vector<string> & v, int r, int c) {
  if ( (r<0) || (r>= v.size()) ) return;
  if ( (c<0) || (c>= v[0].size())) return;
  if (v[r][c] == '*') return;
  v[r][c] = '*';
  for (int i = 0; i < 8; i++) {
    flodd(v, r + dr[i], c + dc[i]); 
  }
}
int main () {
  int m, n;
  string dummy;
  while (true) {
    //scanf("%d %d", &m, &n);
    cin >> m >> n;
    //cout << "<" << m << " " << n << '\n';
    if (m == 0) break;
    getline(cin, dummy);
    vector <string> v(m, string());
    for (int i = 0; i < m; i++) {
      getline(cin, v[i]); 
    }
    //cout << v[2] << '\n';
    int count = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (v[i][j] == '@') {
          count++;
          //cout << i << " " << v[i] << '\n';
          flodd(v, i, j);
        }
      } 
    }   
    cout << count << '\n';
  }
  return 0;
}

