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

bool is(int w1, int h1, int w2, int h2, int w3, int h3) {
  //..
  //--
  if ( w1 == (w2+w3) and (h2 == h3) and (h1 + h2) == (w1) ) return true;
  if ( w1 == w2 and w1 == w3 and (h1 + h2 + h3) == w1 ) return true;
  if (h1 == (h2 + h3) and w2 == w3 and h1 == (w1 + w2)) return true;
  if ( h1 == h2 and h1 == h3 and (w1 + w2 + w3) == h1 ) return true;
  return false;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt; cin >> tt;
  while(tt--) {
    int w1, h1, w2, h2, h3, w3;
    cin >> w1 >> h1 >> w2 >> h2 >>w3 >> h3;
    bool t = false;
    t |= is(w1, h1, w2, h2, w3, h3);
    t |= is(w2, h2, w1, h1, w3, h3);
    t |= is(w3, h3, w2, h2, w1, h1);
    t |= is(h1, w1, h2, w2, h3, w3);
    t |= is(h2, w2, h1, w1, h3, w3);
    t |= is(h3, w3, h2, w2, h1, w1);
    cout << (t? "yes":"no") << '\n';
  }
}


