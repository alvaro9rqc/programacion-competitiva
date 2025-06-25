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

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  ll n, q; cin>> n >> q;
  vl a(n);
  for(auto& e: a) cin >> e;
  for (auto i = 1; i < n; ++i) {
    a[i] += a[i-1];
  }
  for (auto i = 0; i < q; ++i) {
    int l, r; cin>>l >> r;
    --r;
    ll ans;
    if (l ==0) ans = a[r];
    else ans = a[r]-a[l-1];
    cout <<ans <<'\n';
  }
}


