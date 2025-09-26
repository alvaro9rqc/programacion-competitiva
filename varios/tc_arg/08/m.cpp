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

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  double n; double r;
  double pi = acos(-1);
  scanf("%lf, %lf", &n, &r);
  double alfad = 2.0*pi / n / 2.0;
  double R = r * sin(alfad) / (1 - sin(alfad));
  printf("%.8lf\n", R);
}


