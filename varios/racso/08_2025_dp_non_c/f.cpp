#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
#define endl '\n'
#define dbg(x) cerr << #x << " = " << (x) << endl;
#define raya cerr << " ==================== " << endl;
#define rep(i, a, b) for (auto i = a; i < (b); ++i)
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)

vector<string> up;
vector<string> dow;
vector<string> ri;
vector<string> le;

void load(int n, int m, vector<string>& gr) {
  for (auto c = 0; c < m; ++c) up[0][c] = gr[0][c];
  for (auto r = 1; r < n; ++r) 
    for (auto c = 0; c < m; ++c) 
      if (up[r-1][c] or gr[r][c]) up[r][c] = 1;
  for (auto c = 0; c < m; ++c) dow[n-1][c] = gr[n-1][c];
  for (auto r = n-2; r >=0; --r) 
    for (auto c = 0; c < m; ++c) 
      if (dow[r+1][c] or gr[r][c]) dow[r][c] = 1;
  for (auto c = 0; c < n; ++c) le[c][0] = gr[c][0];
  for (auto r = 0; r < n; ++r) 
    for (auto c = 1; c < m; ++c) 
      if (le[r][c-1] or gr[r][c]) le[r][c] = 1;
  for (auto c = 0; c < n; ++c) ri[c][m-1] = gr[c][m-1];
  for (auto r = 0; r < n; ++r) 
    for (auto c = m-2; c >= 0; --c) 
      if (ri[r][c+1] or gr[r][c]) ri[r][c] = 1;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n, m; cin >> n >> m;
  vector<string> gr(n,string(m,0));
  for (auto r = 0; r < n; ++r) {
    for (auto c = 0; c < m; ++c) {
      char x; cin >> x;
      if (x == '1') gr[r][c] = 1;
    }
  }
  up.assign(n,string(m,0));
  dow.assign(n,string(m,0));
  ri.assign(n,string(m,0));
  le.assign(n,string(m,0));
  load(n, m, gr);
  ll ans = 0;
  for (auto r = 0; r < n; ++r) {
    for (auto c = 0; c < m; ++c) {
      if (not gr[r][c]) 
        ans+= up[r][c]+dow[r][c]+ri[r][c]+le[r][c];
    }
  }
  cout << ans <<'\n';
}


