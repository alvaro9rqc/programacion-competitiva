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
vl prr;

using bii = tuple<bool,int,int>;

bii dfs(int u) {
  if(prr[u]) return {1,prr[u],prr[u]};
  vector<bii> li;
  int vidx=int(1e7), idx=0;
  for(auto& v: adj[u]) {
    auto [nc,nl,nr]=dfs(v);
    if(not nc) return {0,0,0};
    li.emplace_back(nc,nl,nr);
    if(nl<vidx)vidx=nl,idx=sz(li)-1;
  }
  int n=sz(li);
  int vmax=get<2>(li[idx]);
  for (auto i = 0; i < sz(li)-1; i++) {
    int j=(idx+1)%n;
    auto [c0,l0,r0]=li[idx];
    auto [c1,l1,r1]=li[j];
    vmax=max(vmax,r1);
    if (r0>=l1) return {0,0,0};
    idx=j;
  }
  return {1,vidx,vmax};
}

void solve() {
  int n;cin>>n;
  adj.assign(n,vi());
  for (auto i = 0; i < n-1; i++) {
    int u;cin>>u;--u;
    adj[u].emplace_back(i+1);
  }
  for(auto& nei: adj) sort(all(nei));
  prr.resize(n);
  for(auto& i: prr) cin >> i; 
  auto [c,l,r]=dfs(0);
  cout<<(c?"yes":"no")<<'\n';
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

