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

ll lis(vl& wei, vl&hei){
  int n=sz(wei);
  vl dp(n);
  ll r = 0;
  for (auto i = 0; i < n; i++) {
    ll ans = 0;
    for (auto j = 0; j < i; j++) 
      if (hei[j]<hei[i])
        ans = max(dp[j], ans);
    dp[i]=ans+wei[i];
    r = max(r, dp[i]);
  }
  return r;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt; cin  >> tt;
  int cases = 0;
  while(tt--) {
    int n;  cin >> n;
    vl hei(n), wei(n);
    for(auto& i: hei) cin >> i;
    for(auto& i: wei) cin >> i;
    ll inc = lis(wei, hei);
    reverse(all(hei));
    reverse(all(wei));
    ll dec = lis(wei, hei);
    string a="Increasing", b = "Decreasing";
    if (dec > inc) swap(a,b), swap(inc,dec);
    cout << format("Case {}. {} ({}). {} ({}).\n", ++cases, a, inc, b, dec);
  }
}


