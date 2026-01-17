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

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt; cin >> tt;
  while(tt--) {
    int n; cin >> n;
    map<int,int> omp;
    for (auto i = 0; i < n; i++) {
      int x; cin >> x;
      ++omp[x];
    }
    bool can = 1;
    if (!omp[0])can=0;
    else if (omp[0]==1)can=1;
    else can=omp[1];
    cout << (can?"yes":"no")<<'\n';
  }
}

