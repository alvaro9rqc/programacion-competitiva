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

int n, m; 
int src, tgt;
vector<vi> adj;
vector<vi> memo;

bool dp(int u, int mask) {
  if (u == tgt) return mask == 0;
  if (memo[u][mask]!=-1) return memo[u][mask];
  bool ans = 0;
  for(auto& v: adj[u]) {
    if ((1<<v)&mask)
      if ((ans=(bool)dp(v, mask&~(1<<v)))) break;
  }
  return (memo[u][mask]=ans);
}

vi st;

void dfs(int u, int mask) {
  if (u == tgt) {
    st.push_back(u);
    return;
  }
  for(auto& v: adj[u]) {
    if ((1<<v)&mask)
      if (dp(v, mask&~(1<<v))) {
        st.push_back(u);
        dfs(v, mask&~(1<<v));
        return;
      }
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt; cin >> tt;
  int cases=0;
  while(tt--) {
    cin >> n >> m;
    adj.assign(n,vi());
    memo.assign(n, vi(1<<n, -1));
    vector<char> arr(n);
    for(auto& i: arr) cin >> i;
    char ori, des;
    ori=arr.front(), des=arr.back();
    sort(all(arr));
    map<char, int> mp;
    for (auto i = 0; i < n; i++) 
      mp[arr[i]]=i;
    src=mp[ori], tgt=mp[des];
    for (auto i = 0; i < m; i++) {
      char x, y; cin >> x >> y;
      adj[mp[x]].emplace_back(mp[y]);
      adj[mp[y]].emplace_back(mp[x]);
    }
    for(auto& li: adj) sort(all(li));
    int mask=(1<<n)-1;
    bool can =dp(src, mask & (~(1<<src)));
    cout << format("Case {}: ", ++cases);
    st.clear();
    if (can) {
      dfs(src, mask & (~(1<<src)));
      for(auto& i: st) cout << arr[i];
      cout <<'\n';
    } else cout << "impossible\n";
  }
}

