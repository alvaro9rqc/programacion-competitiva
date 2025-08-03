#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
#define endl '\n'
#define dbg(x) cerr << #x << " = " << (x) << endl;
#define raya cerr << " ==================== " << endl;
#define FOR(i, a, b) for (auto i = a; i < (b); ++i)
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  // vector de H
  //
  // nw[i] = 1 + rt[i] + nw[i+1]
  //
  // base: if # -> 0
  int h, w;
  int mod = 1e9+7;
  cin >> h >> w;
  vector<string> gr(h);
  for(auto& r: gr) cin >> r;
  vi nw(h+1), rt(h+1);
  rt[h-1] = 1;
  for (auto i = w-1; i >= 0; --i) {
    for (auto r = h-1; r >= 0; --r) {
      if (gr[r][i] == '#')
        nw[r] = 0;
      else 
        nw[r] = rt[r] + nw[r+1], nw[r]%=mod;
      //cerr << r <<' ' <<i <<'\n';
      //cerr << nw[r] <<'\n';
    }
    swap(rt,nw);
  }
  cout << rt[0] <<'\n';
}


