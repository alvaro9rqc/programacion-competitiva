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

bool vp(string& p) {
  for (auto i = 1; i < sz(p); i++) {
    if (p[i-1]>p[i])return 0;
  }
  return 1;
}

bool pal(string& s) {
  int l =0; int r = sz(s)-1;
  while(l < r) {
    if (s[l++]!=s[r--])return 0;

  }
  return 1;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt; cin >> tt;
  while(tt--) {
    int n; cin >> n;
    string s; cin >> s;
    bool exist = 0;
    vi ans;
    for (auto mask = 0; mask < (1<<n); mask++) {
      ans.clear();
      string p="", r="";
      for (auto i = 0; i <n; i++) {
        if ((1<<i)&mask) p.push_back(s[i]), ans.emplace_back(i+1);
        else r.push_back(s[i]);
      }
      if (vp(p) and pal(r)) {
        //dbg(r);
        //dbg(p);
        exist=1;
        break;
      }
    }
    if (exist) {
      cout << sz(ans)<<'\n';
      for(auto& i: ans) cout << i << ' ';
      cout <<'\n';
    } else cout << "-1\n";
  }
}

