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
  int n; cin >> n;
  vl arr(n);
  for(auto& e: arr) cin>>e;
  ll lim = 10001;
  ll mod = ll(1e9+7);
  vl next(lim), now(lim);
  next[arr.back()] = 1;
  ll ans = 0;
  for (auto i = n-2; i >= 0; --i) {
    for (ll k = 0; k < lim; ++k) {
      ll s1 = k - arr[i]; 
      ll s2 = k + arr[i];
      s1 = max(s1, -s1);
      s2 = max(s2, -s2);
      now[k] = 0;
      if(s1<lim)
        now[k] += next[s1];
      if(s2<lim)
        now[k] += next[s2];
      now[k]%=mod;
    }
    ans+=now[0];
    ans%=mod;
    now[arr[i]]++;
    swap(now, next);
  }
  cout << ans <<'\n';
}


