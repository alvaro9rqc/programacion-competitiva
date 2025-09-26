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

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tt; cin >> tt;
  vl fib(12);
  fib[1] = 1;
  fib[2] = 2;
  for (auto i = 3; i < 12; ++i) {
    fib[i] = fib[i-1] + fib[i-2];
  }
  while(tt--) {
    ll n, m; cin >> n >> m;
    vl t1 = {fib[n], fib[n], fib[n+1]};
    vl v(3);
    string ans;
    for (ll i = 0; i < m; ++i) {
      cin >> v[0] >> v[1] >> v[2];
      sort(v.begin(), v.end());
      if (
          t1[0] <= v[0] and
          t1[1] <= v[1] and
          t1[2] <= v[2]
          ) ans.push_back('1');
      else ans.push_back('0');
    }
    cout << ans << '\n';
  }
}


