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

vl arr;
vector<map<ll,ll>>memo;
int n;
ll m;

ll dp(int i, ll s) {
  if (i>=n) return s==0;
  if (memo[i].count(s))return memo[i][s];
  ll ans = 0;
  ans+=dp(i+2,(s+arr[i])%m);
  ans+=dp(i+1,s);
  return memo[i][s]=ans;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  cin >> n >> m;
  arr.assign(n,-1);
  //memo.assign(n,vl(m,-1));
  memo.assign(n, map<ll,ll>());
  for(auto& i: arr) cin >> i;
  cout << dp(0,0)<<'\n';
}

