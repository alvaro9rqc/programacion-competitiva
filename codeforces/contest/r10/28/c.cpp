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
  while(tt--){
    int n; cin >> n;
    vi m(5001, -1);
    vi v(n);
    queue<int> q;
    ll g = 0;
    for(auto& e: v)
      cin>>e, m[e]=0, q.push(e), g = gcd(g, e);
    int ans =0;
    for(auto& e: v) 
      if (e == g) ++ans;

    if (ans) {
      cout << n - ans << '\n';
      continue;
    }

    while(q.size()) {
      int val = q.front();
      q.pop();
      for(auto& e: v) {
        int d = gcd(e,val);
        if (m[d] == -1) {
          m[d] = 1 + m[val];
          q.push(d);
        }
      }
    }
    cout << n + m[g] -1 <<'\n';
  }
}


