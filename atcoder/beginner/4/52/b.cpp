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
  int h,w;cin>>h>>w;
  vector<string> gri(h, string(w,'.'));
  for (auto i = 0; i < h; i++) gri[i].front()='#';
  for (auto i = 0; i < h; i++) gri[i].back()='#';
  for (auto i = 0; i < w; i++) gri.front()[i]='#',gri.back()[i]='#';
  for(auto& r: gri) cout<<r<<'\n';
}

