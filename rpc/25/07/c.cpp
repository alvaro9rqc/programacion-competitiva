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
#define all(x) begin(x), end(x)

int n, p;
vector<double> a;
double pi = atan(1) * 4.0;
vector<vector<vector<double>>> memo;

vector<double> acs;

inline double fast(int i, int j) {
  if (i == 0) return acs[j];
  else return acs[j] - acs[i-1];
}

double dp(int l, int r, int g) {
  if (g == 1) return sin(fast(l, r));
  if (memo[l][r][g] != -1) return memo[l][r][g];
  //cout << l << ' ' << r << ' ' << g << '\n';
  //cout << (memo[l][r][g]==-1) << '\n';
  double ans = 0;
  int d = ((l <= r)? r-l: r+n-l);
  ++d;
  //cout << "d: " << d << '\n';
  for (auto k = 0; k < (d-g+1); ++k) {
    ans = max(ans, sin(fast(l, l+k)) + dp((l+k+1)%n, r, g-1) );
  }
  return memo[l][r][g] = ans;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  cin >> n >> p;
  a.assign(n, 0);
  cin >> a.front();
  auto xd = a.front();
  for (auto i = 1; i < n; ++i) {
    cin >> a[i];
    a[i-1] = a[i] - a[i-1];
  }
  a.back() = xd+360-a.back();
  //cout << "ga: " << a[4]<< '\n';
  for(auto& e: a) e = e / 180.0 * pi;
  //fast sum
  acs.resize(n*2);
  for (auto i = 0; i < n; ++i) {
    acs[i] = acs[i+n] = a[i];
  }
  for (auto i = 1; i < (n<<1); ++i) {
    acs[i] += acs[i-1];
  }
  //cout << "ga: " << a[4]<< '\n';
  memo.assign(n, vector<vector<double>>(n, vector<double>(p+1, -1.0)));
  //cout << "ga: " << memo[0][0][0]<< '\n';
  double ans = 0;
  for (auto i = 0; i < n; ++i) {
    ans = max(ans, dp(i,(n+ (i-1)%n)%n, p) );
  }
  //cout << ans / 2.0 << '\n';
  printf("%.8lf\n" ,ans / 2.0*1e6);
}


