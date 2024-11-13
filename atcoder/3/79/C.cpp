#include <bits/stdc++.h> 
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main () {
  ios_base::sync_with_stdio(false);
  unordered_map <long, long> map;
  long n, m;
  cin >> n >> m;
  vector<long > v(m,0);
  for (long i = 0; i < m; ++i) {
    cin >> v[i]; v[i]--;
    map[v[i]];
  }
  for (long i = 0; i < m; ++i) {
    cin >> map[v[i]];
  }
  long act = 0;
  long movs = 0;
  for (long i = 0; i < n-1; ++i) {
    if (map.find(i) != map.end()) 
      act += map[i];
    if (act > 1) {
      movs += act-1;
      act--;
    }
  }
  if (act != 1) cout << -1 << '\n';
  else cout << movs << '\n';
  return 0;
}


