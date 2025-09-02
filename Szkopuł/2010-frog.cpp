#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
#define dbg(x) cerr << #x << " = " << (x) << endl;
#define raya cerr << " ==================== " << endl;
#define rep(i, a, b) for (auto i = a; i < (b); ++i)
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n, k; cin >> n >>k;
  ll m; cin >> m;
  int lim = 31;
  vector<vi> tel(lim, vi(n));
  {
    vl arr(n);
    for(auto& i: arr) cin >> i;
    for (auto i = 0, l = 0, r = k; i < n; i++) {
      int t = 0;
      if (r < i)++l, ++r;
      while(l != i and r!=n-1) {
        if (arr[i]-arr[l]> arr[r+1]-arr[i]) ++l, ++r;
        else break;
      }
      ll dl = arr[i]-arr[l];
      ll dr = arr[r]-arr[i];
      if (dl >= dr)t = l;
      else t = r;
      tel[0][i] = t;
    }
  }

  for (auto lev = 1; lev < lim; lev++) {
    vi xd(n);
    for (auto i = 0; i < n; i++) {
      xd[i] = tel[lev-1][tel[lev-1][i]];
    }
    for (auto i = 0; i < n; i++) {
      tel[lev][i] = xd[xd[i]];
    }
  }
  //for(auto& i: tel[2]) cout << i <<' ';
  for (auto i = 0; i < n; i++) {
    ll d = 0;
    ll v = i;
    for (auto j = lim-1; j >= 0; j--) {
      int c = j*2;
      if (d + (1ll<<c) <= m) d+=1ll<<(c), v = tel[j][v],++j;
    }
    cout << v+1<<(i == n-1?'\n':' ');
  }
}


