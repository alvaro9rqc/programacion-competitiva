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

ll n; 
vl v,w,m;
vector<vl> memo(10010, vl(110, -1));



int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  ll W; cin >> W;
  v.resize(n);
  w.resize(n);
  m.resize(n);
  for (ll i = 0; i < n; ++i) {
    cin >> v[i] >> w[i] >> m[i];
  }

}


