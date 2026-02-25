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
typedef vector<ll> vll;
typedef vector<ll_p> vll_p;   
typedef vector<ll_t> vll_t;
ll N, M; 

ll mod = 998244353;

ll f(int idx) {
  if (idx < 0) return 0;
  if (idx == 0) return M & 1;

  ll n = (1ll << idx);
  return (( M&n )? 1:0)*(n % mod) + 2*f(idx-1)%mod;
}

ll bt(ll n) {
  if (n == 0) return 0;
  for (int i = 59; i >= 0; --i) {
    if (n & (1ll<<i)) {
      ll vf = f(i-1);
      ll inc = 0;
      if (M & (1ll<<i)) inc += n - (1ll<<i)+1;
      ll ans = inc % mod + vf % mod + bt(n & (( 1ll<<i )-1)) % mod; 
      //cout << i << ' ' << inc <<' '<<vf <<' '<<ans <<'\n';
      return ans % mod;
    }
  }
  return 0;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N >> M;
  if (N == 0) cout << 0 <<'\n';
  else cout << bt(N) % mod<<'\n';
}


