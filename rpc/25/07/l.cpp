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

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  ll h1, d1, t1; 
  ll h2, d2, t2; 
  cin >> h1 >> d1 >> t1;
  cin >> h2 >> d2 >> t2;
  ll g1 = (h2 / d1 + (h2%d1 ? 1:0)-1)*t1;
  ll g2 = (h1 / d2 + (h1%d2 ? 1:0)-1)*t2;
  if (g1 == g2) cout  << "draw\n";
  else if ( g1 > g2 ) cout << "player two\n";
  else cout << "player one\n";
}


