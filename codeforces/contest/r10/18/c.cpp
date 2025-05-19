#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;

typedef pair<ll, ll> ll_p; 
typedef tuple<ll, ll, ll> ll_t; 
typedef vector<ll> vl;
typedef vector<ll_p> vll;   
typedef vector<ll_t> vlll;

vector<vl> g;
vl A, B, C;
const ll INF = 1e13;
vector<vl> memo(2, vl(1000));


ll f(int c, ll i) { 
  if (i == ll(C.size()-1) ) {
    if (c) return C.back();
    else return 0;
  }
  if (memo[c][i] != -1) return memo[c][i];
  ll ans = INF;
  ll inc = 0;
  if (c) {
    for(auto& r: g) ++r[i];
    inc = C[i];
  }
  bool can = true;
  for(auto& r: g) {
    if (r[i] == r[i+1]) {
      can = false;
      break;
    }
    if (not can) break;
  }
  if (can) ans = min(ans, inc + f(0, i+1) );
  can = true;
  for(auto& r: g) {
    if (r[i] == r[i+1] + 1) {
      can = false;
      break;
    }
    if (not can) break;
  }
  if (can) ans = min(ans, inc + f(1, i+1) );
  if (c) 
    for(auto& r: g) --r[i];
  return memo[c][i] = ans;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  while(t--)  {
    ll n; cin >> n;
    fill(memo[0].begin(), memo[0].begin()+n, -1);
    fill(memo[1].begin(), memo[1].begin()+n, -1);
    g.assign(n, vl(n));
    for(auto& r: g) 
      for(auto& c: r) cin >> c;
    A.assign(n, 0);
    B.assign(n, 0);
    for(auto& e: A) cin >> e;
    for(auto& e: B) cin >> e;
    C.swap(B);
    ll ans1 = min(f(0, 0), f(1, 0));
    for (ll i = 0; i < n; ++i) {
      for (ll j = 0; j < i; ++j) {
        swap(g[i][j], g[j][i]);
      }
    }
    fill(memo[0].begin(), memo[0].begin()+n, -1);
    fill(memo[1].begin(), memo[1].begin()+n, -1);
    C.swap(A);
    ll ans2 = min(f(0, 0), f(1, 0));
    if (ans1 == INF or ans2 == INF) cout << -1 << '\n';
    else cout << ans1 + ans2 << '\n';
  }
}


