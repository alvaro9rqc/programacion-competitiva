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
    ll a, b; cin >> a >> b;
    swap(a,b);
    bool ap = a%2==0;
    bool bp = b%2==0;
    ll ans = -1;
    if (ap and bp) {
      ans=(2 + b*a/2);
    } else if(ap and not bp) {
      if (a%4 == 0) ans = 2+b*a/2;
      else ans =-1;
    } else if (not ap and bp) {
      ans=-1;
    } else {
      ans=1+a*b;
    }
    cout << ans <<'\n';
  }
}


