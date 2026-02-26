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
  int tt;cin>>tt;
  while(tt--) {
    ll n;cin>>n;
    set<ll> fp;
    for (auto i = 2; i*i <= n; i++) {
      if (n%i==0)
        fp.emplace(i);
      while(n%i==0) {
        n/=i;
      }
    }
    if (n!=1) fp.emplace(n);
    ll ans = 1;
    for(auto& i: fp) ans*=i;
    cout<<ans<<'\n';
  }
}

