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
ll f(vi& a, vi& b) {
  ll ans = 0;
  for (auto i = 0; i < n; i++) {
    int k = i;
    int can = 1;
    for (auto j = 0; j < n; j++, k = (k+1)%n) {
      if(a[k]>=b[j]) {can=0;break;}
    }
    ans+=can;
  }
  return ans;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt; cin >> tt;
  while(tt--) {
    cin >> n;
    vi a(n),b(n),c(n);
    for(auto& i: a) cin>>i;
    for(auto& i: b) cin>>i;
    for(auto& i: c) cin>>i;
    cout << ll(n)*f(a,b)*f(b,c)<<'\n';
  }
}

