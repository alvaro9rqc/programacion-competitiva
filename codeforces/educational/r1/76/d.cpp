#include <bits/stdc++.h> 
using namespace std;
using ll = unsigned long long;
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

map<tuple<int,ll,ll>, ll> memo;

const ll INF = LLONG_MAX/4;

ll dp(int k, ll x , ll y) {
  if (k == 19) return INF;
  if (x == y) return 0;
  if(memo.find({k,x,y}) != memo.end()) return memo[{k,x,y}];
  ll inc = 1ull << k;
  ll ans = inc + min(
      dp(k+1, x >> k, y), 
      dp(k+1, x, y >> k)
      );
  return memo[{k,x,y}] = min(ans, dp(k+1, x,y));
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T; cin >> T;
  while(T--) {
    ll x, y;
    cin >> x >> y;
    //memo.clear();
    cout << dp(0, x,y) <<'\n';
  }
}


