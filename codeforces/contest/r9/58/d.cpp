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

vector<vl>memo;
vl val;
vector<vi> adj1,adj;

ll dp(bool t, int i) {
  if(memo[t][i]!=-1)return memo[t][i];
  auto& ans=memo[t][i];
  if(t){
    ans=val[i];
    for(auto& v: adj[i]) ans+=dp(0,v);
  } else {
    ans=0;
    for(auto& v: adj[i]) ans+=max(dp(1,v), dp(0,v));
  }
  return ans;
}

void dfs(int u, int p) {
  for(auto& v: adj1[u]) {
    if(v==p) continue;
    adj[u].emplace_back(v);
    dfs(v,u);
  }
}

void solve() {
  int n;cin>>n;
  val.resize(n);
  memo.assign(
    2, vl(n,-1)
  );
  adj1.assign(n,vi());
  adj.assign(n,vi());
  ll s=0;
  for(auto& i: val) cin >> i,s+=i; 
  for (auto i = 0; i < n-1; i++) {
    int u,v;cin>>u>>v;
    --u,--v;
    adj1[u].emplace_back(v);
    adj1[v].emplace_back(u);
  }
  dfs(0,0);
  cout<<s*2-max(dp(0,0),dp(1,0))<<'\n';
  // for(auto& v: adj[0]) cout<<v<<"\n";
  // raya;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt=1;
  cin>>tt;
  while(tt--) {
    solve();
  }
}

