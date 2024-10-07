#include <bits/stdc++.h> 
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main () {
  ios_base::sync_with_stdio(false);
  int n, x; 
  while (cin >> n) {
    if (n == 0) break;
    vector<vi> g(n, vi());
    while (cin >> x) {
      if (x == 0) break;
      --x;
      string line; getline(cin, line);
      stringstream s(line);
      int v; while (s >> v) {
        --v;
        g[x].push_back(v);
        g[v].push_back(x);
      }
    }

  }
  return 0;
}


