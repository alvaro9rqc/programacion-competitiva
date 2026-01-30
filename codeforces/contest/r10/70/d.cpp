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

ll mod = 998244353;

vector<map<ll,vi>> edg;
vector<map<ll,ll>> memo;
vl val;
vector<vi> adj;

ll dp(int i, ll s) {
  if (!edg[i].count(s)) return 0;
  if(memo[i].count(s)) return memo[i][s];
  auto& v = edg[i][s];
  ll ans = sz(v);
  for(auto& j: v) ans+=dp(j, val[i]+val[j]),ans%=mod;
  return memo[i][s]= ans;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt; cin >> tt;
  while(tt--) {
    int n,m; cin >> n>>m;
    val.resize(n);
    for(auto& i: val) cin >> i;
    edg.assign(n, map<ll, vi>());
    memo.assign(n, map<ll,ll>());
    adj.assign(n, vi());
    for (auto i = 0; i < m; i++) {
      int a, b; cin >> a >> b;
      --a,--b;
      adj[a].emplace_back(b);
      edg[a][val[b]].emplace_back(b);
    }
    ll ans = 0;
    set<pair<int,ll>> vis;
    for (auto i = 0; i < n; i++) {
      for(auto& v: adj[i]) {
        if (vis.count({i,val[v]}))continue;
        ans+=dp(i,val[v]),ans%=mod;
        //dbg(i);
        //dbg(v);
        //dbg(dp(i,val[v]));
        vis.emplace(i,val[v]);
      }
    }
    cout << ans <<'\n';
  }
}


