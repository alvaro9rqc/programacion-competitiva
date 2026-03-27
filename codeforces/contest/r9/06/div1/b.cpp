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
  using pl = pair<ll,ll>;
  while(tt--) {
    ll n, c;cin>>n>>c;
    vector<pl> val;
    ll s=0;
    for (auto i = 1; i < n+1; i++) {
      ll x;cin>>x;
      if(i==1)s+=x;
      else
        val.emplace_back((i)*c-x, x);
    }
    sort(all(val));
    int xd = 1;
    for(auto& [d,x]: val) {
      if(s<d)break;
      s+=x;
      ++xd;
    }
    cout<<(xd==n?"yes":"no")<<'\n';
  }
}

