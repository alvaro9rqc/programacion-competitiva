#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
#define dbg(x) cerr << #x << " = " << (x) << endl;
#define raya cerr << " ==================== " << endl;
#define rep(i, a, b) for (auto i = a; i < (b); ++i)
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)

vi fac;
vi memo;
int lim = int(1e5*10);

int dp(int n) {
  if (n == 0) return 0;
  if (memo[n] != -1) return memo[n];
  int ans = lim;
  for(auto& f: fac) 
  if  (f <= n) ans = min(ans,1+dp(n-f));
  return memo[n] = ans;
}


int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; 
  for (auto i = 1,x=1; x < lim; i++) 
    fac.emplace_back(x*=i);
  memo.assign(lim,-1);
  while(cin>>n) {
    cout << dp(n) <<'\n';
  }
}

