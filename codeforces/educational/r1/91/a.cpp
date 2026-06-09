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

void solve() {
  ll n,x,y,z;cin>>n>>x>>y>>z;
  ll t1 = n/(x+y) + ((n%(x+y))?1:0);
  ll t2;
  if(z*x<=n) t2=z+(n-z*x)/(x+10*y)+ (((n-x*z)%(x+10*y))?1:0);
  else t2=n/x+(n%x?1:0);
  cout<<min(t1,t2)<<'\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt=1;
  cin>>tt;
  while(tt--) {
    solve();
  }
}

