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

vi x, y;
vector<double>memo;

double inf =(1e9);
int n;

double dist(int i, int j) {
  return sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
}

double dp(int mask) {
  if (memo[mask]!=-1) return memo[mask];
  double ans = inf;
  for (auto i = 0; i < n; i++) {
    if (not (mask&1<<i)) continue;
    for (auto j = i+1; j < n; j++) {
      if (mask&1<<j) {
        ans = min(ans, dist(i,j) + dp( mask & ~(1<<i | 1<<j) ));
      }
    }
  }
  return memo[mask]=ans;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int cases = 0;
  while(1){
    cin >> n;
    if (not n) break;
    n<<=1;
    string s; 
    x.assign(n,1);
    y.assign(n,1);
    memo.assign(1<<n, -1);
    memo[0]=0;
    for (auto i = 0; i < n; i++) {
      cin >> s >> x[i]>>y[i];
    }
    printf("Case %d: ", ++cases);
    printf("%.2lf\n",(dp((1<<n)-1)) );
  }
}

