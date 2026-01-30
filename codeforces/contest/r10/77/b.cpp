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
    string s; cin >> s;
    int l=0, r=n-1;
    for (; l < n and s[l]!='1'; ++l);
    for (; r >= 0 and s[r]!='1'; --r);
    if (r<l) {
      int ans = n/3+(n%3?1:0);
      cout << ans<<'\n';
      continue;
    }
    ll ans = 0;
    if(l>1)
      ans+=(l-2)/3+1;
    if (n-r-1>1)
      ans+=(n-r-3)/3+1;
    for (auto j = l+1; j < r+1; j++) {
      if (s[j]=='1') {
        //dbg(j);
        auto x = j-l-1;
        ans+=x/3;
        l=j;
      }
    }
    for(auto& i: s) 
      if(i=='1')++ans;
    cout << ans <<'\n';
  }
}

