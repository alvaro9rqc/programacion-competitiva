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
  int tt; cin >> tt;
  int ttc = 0;
  while(ttc++ < tt) {
    ll n; cin >> n;
    n--;
    vl a(n);
    for(auto& e: a) cin>>e;
    ll ans = a[0];
    int j=0, l=0, r=0;
    ll v = 0;
    for (auto i = 0; i < n; ++i) {
      v += a[i];
      if (v > ans) {
        l = j; r = i;
        ans = v;
      } else if (v == ans) {
        if (i - j > r - l) r=i,l=j; 
      }
      if (v < 0) v = 0, j = i+1;
    }
    if (ans < 0) printf("Route %d has no nice parts\n", ttc);
    else printf("The nicest part of route %d is between stops %d and %d\n", ttc, l+1, r+2 );
  }
}
