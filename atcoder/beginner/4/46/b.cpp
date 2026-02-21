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
  int n,m;cin>>n>>m;
  vector<bool>ava(m+10,1);
  for (auto i = 0; i < n; i++) {
    int x = 0;
    int l;cin>>l;
    for (auto j = 0; j < l; j++) {
      int y;cin>>y;
      if (x==0 and ava[y]) {
        ava[y]=0;
        x=y;
      }
    }
    cout<<x<<'\n';
  }
}

