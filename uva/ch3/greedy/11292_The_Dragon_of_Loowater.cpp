#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
#define endl '\n'
#define dbg(x) cerr << #x << " = " << (x) << endl;
#define raya cerr << " ==================== " << endl;
#define rep(i, a, b) for (auto i = a; i < (b); ++i)
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n, m;
  while(1) {
    cin >> n >> m;
    if (n == 0 and m == 0) break;
    vl cab(n), kni(m);
    for(auto& i: cab) cin >> i;
    for(auto& i: kni) cin >> i;
    sort(all(cab));
    sort(all(kni));
    ll cost = 0;
    int idx = 0;
    for(auto& k: kni) {
      if (k >= cab[idx]) ++idx, cost+=k;
      if (idx == n) break;
    }
    if (idx != n) cout << "Loowater is doomed!\n";
    else cout << cost<<'\n';
  }
}


