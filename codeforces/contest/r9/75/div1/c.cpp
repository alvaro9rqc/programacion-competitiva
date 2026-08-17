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

vi deep,ans;
vector<vi> adj;

int dfs(int u, int p) {
  deep[u]=deep[p]+1;
  ans[deep[u]]--;
  int m = deep[u];
  for(auto& v: adj[u]) {
    if(deep[v]==-1)m=max(m,dfs(v,u));
  }
  ans[m+1]++;
  return m;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt;cin>>tt;
  while(tt--) {
    int n;cin>>n;
    deep.assign(n,-1);
    ans.assign(n+12,0);
    adj.assign(n,vi());
    for (auto i = 0; i < n-1; i++) {
      int a,b;cin>>a>>b;
      --a,--b;
      adj[a].emplace_back(b);
      adj[b].emplace_back(a);
    }
    int l = dfs(0,0);
    int a = n-1;
    for (auto i = 0; i < l+1; i++){
      if(i) ans[i]+=ans[i-1];
      a=min(a,ans[i]+n);
    }
    cout<<a<<'\n';
  }
}

