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
    ll n,m;cin>>n>>m;
    vl val(n);
    for(auto& i: val) cin >> i; 
    ll len=1;
    for (ll l = 0,r=0; l < n and r < n;) {
      if(val[l]==val[r]) {
        len=max(len,r-l+1);
        ++r;
      } else ++l;
    }
    cout<<(len<m?"yes":"no")<<'\n';
  }
}

