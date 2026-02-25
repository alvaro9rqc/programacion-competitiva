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
  int n, k; cin >> n >> k;
  ll x; cin >> x;
  vl arr(n); for(auto& i: arr) cin >> i;
  sort(arr.rbegin(), arr.rend());
  int i=n-k;
  ll w=0;
  for (; i < n; i++) {
    w+=arr[i];
    if (w>=x)break;
  }
  ll ans;
  if (i==n)ans=-1;
  else ans = i+1;
  cout << ans <<'\n';
}

