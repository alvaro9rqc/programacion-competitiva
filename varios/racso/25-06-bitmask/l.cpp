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

vl memo(1ll<<18, -1);
vl ans(1ll<<18, 0);
vl x(20);
ll n;

ll dp(ll q) {
  if (memo[q] != -1) return memo[q];
  ll r = 0;
  ll xo = 0;
  //ll f = -1;
  for (auto i = 0; i < n; ++i) {
    if ((1ll<<i) & q) {
      ll u = q & ~(1ll<<i);
      if (memo[u] == -1) r += dp(u);
      ans[q] += memo[u];
      xo ^= x[i];
    }
  }
  r += xo;
  ans[q]+=xo;
  //printf("q:%lld   r: %lld    ans:%lld\n",q,r,ans[q]   );
  return memo[q] = r;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  memo[0]=0;
  ans[0]=0;
  ll q;
  cin >> n>>q;
  for (ll i = n-1; i >= 0; --i) {
    cin >> x[i];
  }
  dp (( 1ll<<n )-1);
  while(q--){
    string s; cin >> s;
    ll qi = stoll(s, nullptr, 2);
    cout << ans[qi] <<'\n';
  }
}


