#include <bits/stdc++.h> 
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF =  1000;
const int LIM = 101;
int m[LIM][LIM];

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int a, b, v;
  while (true) {
    for (auto i = 1; i < LIM; ++i) {
      for (auto j = 1; j < LIM; ++j) 
        m[i][j] = INF;
      m[i][i] = 0;
    }
    cin >> a >> b;
    v =max(a,b);
    if (a == 0 and b == 0) break;
    m[a][b] = 1;
    while (true) {
      cin >> a >> b; if (a == 0 and b == 0) break;
      m[a][b] = 1;
      v = max ( v, max(a, b) );
    }
    for (auto k = 1; k <= v; ++k) 
      for (auto i = 1; i <= v; ++i) 
        for (auto j = 1; j <= v; ++j) 
          m[i][j] = min(m[i][j], m[i][k] + m[k][j]);
    long sum = 0;
    for (auto i = 1; i <= v; ++i) {
      for (auto j = 1; j <= v; ++j) {
        sum += m[i][j];
        if (m[i][j] == INF) cout << "-> " << i <<' ' << j << " : " << m[i][j] << '\n';
      }
    }
    cout << sum << ' ' << v << '\n';
    cout << sum * 1.0 / (v * (v-1))<< '\n';
  }
  return 0;
}


