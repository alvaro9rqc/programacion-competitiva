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
    ll ans = 0;
    int n;cin>>n;
    vl val(n), tad(n);
    for (auto i = 0; i < n; i++) {
      cin>>val[i];
      ans+=val[i];
      tad[i]=-val[i]+2*(1+i);
    }
    ll s = 0;
    ll r = tad[0];
    for (auto i = 0; i < n; i++) {
      s+=tad[i];
      r = max(r, s);
      if(s<0)s=0;
    }
    if(r<0)r=0;
    cout<<ans+r<<'\n';
  }
}

