#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
#define endl '\n'
#define dbg(x) cerr << #x << " = " << (x) << endl;
#define raya cerr << " ==================== " << endl;
#define rep(i, a, b) for (auto i = a; i < (b); ++i)
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n, k; cin >> n >> k;
  vi arr(n);
  for(auto& i: arr) cin >> i;
  vl next(k+1), now = next; 
  next[0] = 1;
  ll mod = ll(1e9+7);
  if (arr.back() <= k)
    next[arr.back()] = 1;
  for (auto i = n-2; i >= 0; --i) {
    for (auto j = 0; j <= k; ++j) {
      ll ans = 0;
      ans += next[j];
      if (arr[i] <= j) ans+= next[j-arr[i]];
      now[j] = ans%mod;
    }
    swap(now,next);
  }
  cout << next[k] <<'\n';
}


