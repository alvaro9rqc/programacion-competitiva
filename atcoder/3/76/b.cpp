#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
int n, q;
int r, l;

int move(int o, int e, int d) {
  int dd = d - o;
  if (dd < 0) dd += n;
  int de = e - o;
  if (de < 0) de += n;
  if (de < dd) {
    //estorba
    return n - dd;
  } else return dd;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> q;
  char c;
  r = 2;
  l = 1;
  int ans = 0;
  for (auto i = 0; i < q; ++i) {
    cin >> c;
    int m; cin >> m;
    if (c == 'R') {
      //cout << move(r, l , m)<<'\n';
      ans += move(r, l, m);
      r = m;
    } else {
      //cout << move(r, l , m)<<'\n';
      ans += move(l, r, m);
      l = m;
    }
  }
  cout << ans << '\n';
  return 0;
}


