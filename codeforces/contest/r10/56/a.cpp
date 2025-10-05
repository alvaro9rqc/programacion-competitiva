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
  int tt; cin >> tt; 
  while(tt--) {
    int n; cin >> n;
    ll ans = 0;
    ll w = n;
    ll l = 0;
    while(not (w==1 and l == 1)) {
      ll nw=0,nl=0;
      ans+=w/2;
      nw = w/2 + (w&1);
      ans+=l/2;
      nl=w/2+(l/2+(l&1));
      w = nw;
      l = nl;
      //dbg(nw);
      //dbg(nl)
    }
    cout << ++ans <<'\n';
  }
}

