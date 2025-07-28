#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
#define endl '\n'
#define dbg(x) cerr << #x << " = " << (x) << endl;
#define raya cerr << " ==================== " << endl;
#define FOR(i, a, b) for (auto i = a; i < (b); ++i)
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  const int n = (1<<16);
  bitset<n> isprime;
  vl exp(n);
  isprime.set();
  isprime[0]= isprime[1] = 0;
  for (ll i = 2; i < n; ++i) {
    if (isprime[i]) {
      for (ll j = i*i; j < n; j+=i) isprime[j] = 0;
    }
    exp[i] = (ll)ceil(64 / (log(i) / log(2)));
  }
  vl ans = {1};
  bitset<n> used;
  for (ll i = 2; i < n; ++i) {
    if (used[i]) continue;
    for (ll j = i*i; j < n; j*=i) used[j]= 1;
    ll x = i*i*i;
    for (ll e = 4; e < exp[i]; ++e) {
      x *= i;
      //if ( x < 0 ) cerr << "gaaa: " << x <<' '<<i<<' ' << exp[i] <<' ' << e<< '\n';
      if (isprime[e]) continue;
      ans.emplace_back(x);
    }
  }
  sort(all(ans));
  for(auto& e: ans) cout << e << '\n';
  //for (auto i = 0; i < 15; ++i) {
  //  cout << ans[i] << '\n';
  //}
}


