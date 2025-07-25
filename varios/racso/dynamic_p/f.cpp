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

vector<vl>memo(10010, vl(110, -1));
ll n;
vl w, v;

ll f(ll c, ll i) {
  if (i>= n) return 0;
  if (memo[c][i] != -1) return memo[c][i];
  ll ans = f(c, i+1);
  if (c >= w[i]) ans = max(ans, f(c-w[i], i+1) + v[i]);
  return memo[c][i] = ans;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  ll W; cin >> n >> W;
  v.resize(n);
  w.resize(n);
  for (auto i = 0; i < n; ++i) 
    cin >> v[i] >> w[i];
  //for(auto& e: v) cout << e <<(&e == &v.back()?'\n':' ');
  cout << f(W, 0) <<'\n';
}


