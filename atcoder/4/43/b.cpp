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
  ll n, k;
  cin >> n >> k;
  ll ac = n;
  int y = 0;
  if (ac>=k) {
    cout << 0 <<'\n';
    return 0;
  }
  while(1){
    ac+=++n;
    ++y;
    if (ac >= k) break;
  }
  cout << y <<'\n';
  return 0;
}

