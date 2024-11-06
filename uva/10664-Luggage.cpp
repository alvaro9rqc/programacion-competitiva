#include <bits/stdc++.h> 
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int memo[21][21];

vi a(21);

int x(int i, int j) {
  if (i == j) return a[i];
  if (memo[i][j] != -1) return memo[i][j];
  int m = abs( a[i] - x(i+1, j) );
  for (auto k = i+1; k < j; ++k) {
    int t = abs( x(i,k) - x(k+1,j) );
    if (t < m) m = t;
  }
  return memo[i][j] = m;
}

int main () {
  ios_base::sync_with_stdio(false);
  int m;
  string line;
  cin >> m >> ws;
  while (m--) {
    memset(memo, -1, sizeof memo);
    getline(cin, line);
    stringstream s(line);
    int in;
    int idx=0;
    while(s >> a[idx++]) {}
    if (0 == x(0,idx-2)) cout <<"YES\n";
    else cout << "NO\n";
  }
  return 0;
}


