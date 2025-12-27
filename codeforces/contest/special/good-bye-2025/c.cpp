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
vl memo1, memo2,arr, sf;

ll inf = ll(1e16);

ll dp2(int);
ll dp(int);

ll dp2(int i) {
  if (i == n-1) return 0;
  if (memo2[i]!=inf)return memo2[i];
  return memo2[i]= -arr[i] + max(dp(i+1), dp2(i+1));
}

ll dp(int i) {
  if (i == n-1) return 0;
  if (memo1[i]!=inf) return memo1[i];
  ll ans = arr[i]+dp(i+1);
  ans = max(ans, -sf[i+1]);
  ans = max(ans, arr[i]+dp2(i+1));
  return memo1[i]=ans;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt; cin >> tt;
  while(tt--) {
    cin >> n;
    arr.resize(n);
    sf.resize(n);
    for(auto& i: arr) cin>>i;
    sf.back()=arr.back();
    for (auto i = n-2; i >=0; i--) {
      sf[i]=arr[i]+sf[i+1];
    }
    memo1.assign(n,inf);
    memo2.assign(n,inf);
    cout << dp(0)<<'\n';
  }
}

