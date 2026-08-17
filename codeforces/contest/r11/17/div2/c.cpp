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

void solve() {
  int n;cin>>n;
  vector<vi> adj(n+1);
  for (auto i = 0; i < n-1; i++) {
    int x;cin>>x;
    adj[x].emplace_back(i+2);
  }
  int m;cin>>m;
  vector<int> ans;
  vector<bool> dk(n+1,0);
  for (auto i = 0; i < m; i++) {
    int a;cin>>a;
    dk[a]=1;
  }

  auto f=[&](auto&&self, int u)->void {
    for(auto& v: adj[u]) self(self,v);
    if(dk[u])ans.emplace_back(u);
  };
  f(f,1);

  cout<<(m-1)<<' ';
  for (auto i = 0; i < m-1; i++) {
    cout<<ans[i]<<' ';
  }
  cout<<'\n';
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

