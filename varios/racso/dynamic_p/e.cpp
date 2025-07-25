#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
#define endl '\n'
#define dbg(x) cerr << #x << " = " << (x) << endl;
#define raya cerr << " ==================== " << endl;
#define FOR(i, a, b) for (auto i = a; i < (b); ++i)
#define sz(x) (int)(x).size()

vl memo;
vl a;
ll n;

ll f(ll l) {
  if (memo[l] != -1) return memo[l];
  ll m = (l>>1);
  ll ans = a[l];
  for (ll i = 1; i <= m; ++i) {
    ans = max(ans, f(i) + f(l -i));
  }
  return memo[l]=ans;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  cin >> n;
  a.assign(n+9,1);
  memo.assign(n+9, -1);
  for (ll i = 0; i < n; ++i) {
    cin >>a[i+1];
  }
  cout << f(n) <<'\n';
  
}


