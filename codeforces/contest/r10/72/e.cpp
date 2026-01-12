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

struct D {
  int l, j, v;
  D(int a, int b, int c):l(a),j(b),v(c);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt; cin >> tt;
  while(tt--) {
    int n; cin >> n;
    vector<D> arr;
    int xd; cin >> xd;
    vector<vi> s(n+1);
    for (auto i = 1; i < n; i++) {
      int x; cin >> x;
      arr.push_back({i,i,x-xd});
      vi[x-xd].emplace_back(i);
      xd=x;
    }
    vector<bool>vis(n+4);
    for (auto i = n-1; i >= 0; i--) {
      queue<int> que;
      for(auto& j: s[i]) que.emplace(j),vis[j]=1;
      while(sz(que)){

      }
    }
  }
}

