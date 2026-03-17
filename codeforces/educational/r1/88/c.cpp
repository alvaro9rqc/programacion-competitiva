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

ll f(ll a, ll b, ll c, ll m) {
  return m/a*6 - 3*(m/lcm(a,b) + m / lcm(a,c)) + 2*(m/lcm(a,lcm(b,c)));
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt;cin>>tt;
  while(tt--) {
    ll a,b,c,m;cin>>a>>b>>c>>m;
    cout
      <<f(a,b,c,m)<<' '
      <<f(b,a,c,m)<<' '
      <<f(c,a,b,m)<<'\n';
  }
}

