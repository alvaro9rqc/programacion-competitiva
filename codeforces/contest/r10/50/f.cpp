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

int n;
vector<vi> mtx;
vector<bool> used;
int inf = int(1e7);

void menores(vi& lis, int i) {
  int vmin = inf;
  for (auto r = 0; r < n; r++) {
    if (used[r] or i >= sz(mtx[r])) continue;
    vmin = min(vmin, mtx[r][i]);
  }
  for (auto r = 0; r < n; r++) {
    if (used[r] or i >= sz(mtx[r])) continue;
    if (mtx[r][i] == vmin) lis.emplace_back(r);
  }
}

int des(vi& ids, int i) {
  if (sz(ids)== 1) return ids[0];
  for(auto& r: ids) if (sz(mtx[r]) == i) return r;
  vi ids2;
  int vmin = inf;
  for(auto& r: ids) vmin=min(vmin, mtx[r][i]);
  for(auto& r: ids) if (mtx[r][i]==vmin)ids2.emplace_back(r);
  return des(ids2, i+1);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt;
  cin >> tt;
  while(tt--) {
    cin >> n;
    used.assign(n, 0);
    mtx.resize(n);
    for(auto& s: mtx) {
      int k; cin>>k;
      s.resize(k);
      for(auto& i: s) cin>>i;
    }
    vi ans;
    int i = 0;
    while(1) {
      vi ids;
      menores(ids, i);
      if (sz(ids) == 0) break;
      auto idx = des(ids, i+1);
      used[idx] = 1;
      for (; i < sz(mtx[idx]); i++) 
        ans.push_back(mtx[idx][i]);
    }
    for(auto& e: ans) cout << e <<' ';
    cout <<'\n';
  }
}

