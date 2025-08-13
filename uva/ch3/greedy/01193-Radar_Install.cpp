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
  ll n, d;
  int casos = 0;
  while (1) {
    ++casos;
    cin >> n >> d;
    if (n == 0 && d == 0)
      break;

    vector<pair<ll, ll>> par(n);
    for (size_t i = 0; i < par.size(); ++i) {
      cin >> par[i].first >> par[i].second;
    }

    sort(all(par));
    vl r(n);
    bool can = true;
    for (ll i = 0; i < n; ++i) {
      ll x = par[i].first;
      ll y = par[i].second;
      ll xd = d * d - y * y;
      if (xd < 0) {
        can = false;
        break;
      }
      r[i] = xd;
    }
    if (!can) {
      cout << "Case " << casos << ": " << "-1\n";
      continue;
    }

    auto match = [&par, &r](int i, int j) {
      ll x1 = par[i].first;
      ll x2 = par[j].first;
      ll r12 = r[i];
      ll r22 = r[j];
      ll xd = (x2 - x1) * (x2 - x1) - (r12 + r22);
      if (xd < 0)
        return true;
      return 4 * (r12 * r22) >= xd * xd;
    };

    int idx = 0;
    vector<bool> vis(n, false);
    vis[0] = true;
    int ans = 1;
    while (!vis.back()) {
      for (int i = idx + 1; i < n; ++i) {
        bool ac = true;
        for (int j = idx; j < i; ++j) {
          if (!match(j, i)) {
            ac = false;
            break;
          }
        }
        vis[i] = true;
        if (!ac) {
          ++ans;
          idx = i;
          break;
        }
      }
    }
    cout << "Case " << casos << ": " << ans << '\n';
  }
}

