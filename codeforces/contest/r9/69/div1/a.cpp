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

vector<vi> adj;
vi val;
int h1,h0,hi;

void dfs(int u, int p) {
  bool l = 1;
  for(auto& v: adj[u]) {
    if(v==p) continue;
    l=0;
    dfs(v,u);
  }
  if(l) {
    if(val[u]==2)++hi;
    else val[u]?++h1:++h0;
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt;cin>>tt;
  while(tt--) {
    int n;cin>>n;
    adj.assign(n,vi());
    val.resize(n);
    for (auto i = 0; i < n-1; i++) {
      int u, v;cin>>u>>v;
      --u,--v;
      adj[u].emplace_back(v);
      adj[v].emplace_back(u);
    }
    int m = 0;
    for (auto i = 0; i < n; i++) {
      char x;cin>>x;
      if(x=='?')val[i]=2,++m;
      else val[i]=(x-'0');
    }
    h1=h0=hi=0;
    dfs(0,0);
    int ans = 0;
    m=(m-h0-h1-hi-(val[0]==2));
    if(val[0]==2) {
      ans=max(h1,h0)+hi/2;
      ans=max(ans, hi/2+(m&1?hi&1:0) + min(h1,h0));
      // dbg(hi/2+(m&1?hi&1:0));
      // dbg(m);
      // dbg(n);
    }
    else ans=(val[0]?h0:h1)+hi/2+(hi&1);
    // dbg(h1);
    // dbg(h0);
    // dbg(hi);
    cout<<ans<<'\n';
  }
}

