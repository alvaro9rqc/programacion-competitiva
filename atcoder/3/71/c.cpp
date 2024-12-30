#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  set<ii> g, h;
  int mg, mh; cin >> mg;
  for (auto i = 0; i < mg; ++i) {
    int x,y; cin >> x >> y;
    g.emplace(x,y);
    g.emplace(y,x);
  }
  cin >> mh;
  for (auto i = 0; i < mh; ++i) {
    int x,y; cin >> x >> y;
    h.emplace(x,y);
    h.emplace(y,x);
  }
  vector<vi> A(n+1, vi(n+1));
  for (auto i = 1; i < n; ++i) {
    for (auto j = i+1; j <= n; ++j) {
      cin >> A[i][j];
      A[j][i]=A[i][j];
    }
  }
  vi p(n);
  iota(p.begin(), p.end(), 1);
  int ans = INT_MAX; 
  do {
    int w = 0;
    for (auto i = 0; i < n; ++i) {
      for (auto j = i+1; j < n; ++j) {
        if ( (g.find({i+1,j+1})== g.end()) != (h.find({p[i],p[j]}) == h.end()) )
          w += A[p[i]][p[j]];
      }
    }
    ans = min(ans, w);
  } while(next_permutation(p.begin(), p.end()));
  cout << ans <<'\n';
  return 0;
}


