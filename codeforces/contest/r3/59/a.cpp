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


vl to_7(ll n) {
  vl cifras;
  while (n >= 7) {
    cifras.push_back(n%7);
    n/=7;
  }
  cifras.push_back(n);
  reverse(cifras.begin(), cifras.end());
  return cifras;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, m; cin >> n >> m;
  vl cn = to_7(n-1);
  vl cm = to_7(m-1);
  auto f = [](vl& v){
    // len (v), 2^7, 2 (lim)
    vector<vector<vector<ll>>> memo(v.size()+1, vector<vector<ll>>(1ll<<7, vl(2, 0)));
    memo[0][0][1] = 1; // n números que a las i (0) cifras, su representación del set de sus cifras sea (0)
    for (auto i = 0u; i < v.size(); ++i) {
      for (ll j = 0; j < (1ll<<7); ++j) {
        for (ll k = 0; k <= v[i]; ++k) {
          if (j & (1<<k)) continue;
          memo[i+1][j|(1<<k)][ k <v[i] ] += memo[i][j][1];
        }
        for (ll k = 0; k < 7; ++k) {
          if (j & (1<<k)) continue;
          memo[i+1][j|(1<<k)][0] = memo[i][j][0];
        }
      }
    }
    vl ans(1<<7);
    for (ll i = 0; i < (1ll<<7); ++i) 
      ans[i] = memo[v.size()][i][0] +  memo[v.size()][i][1];
    return ans;
  };
  ll ans = 0;
  auto vn = f(cn);
  auto vm = f(cm);
  for (ll i = 0; i < (1<<7); ++i) {
    for (auto mi = 0; mi < (1<<7); ++mi) {
      if (not(i & mi)) ans += vn[i]*vm[mi];
    }
  }
  cout << ans << '\n';
}


