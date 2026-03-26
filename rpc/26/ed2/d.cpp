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

const int alpha = 17;
struct Node {
  // (nmatches i s optional )
  int next[alpha];
  Node() { memset(next, -1, sizeof(next)); }
};
vector<Node> N(1);

int f(int n, int c) {
  int& m = N[n].next[c];
  if (m == -1) { n = m = sz(N); N.emplace_back(); }
  else n = m;
  return n;
}

vector<vi> adj;
vi val;

void dfs(int u, int p, int n) {
  n=f(n,val[u]);
  for(auto& v: adj[u]) {
    if(v==p)continue;
    dfs(v,u,n);
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n;cin>>n;
  val.assign(n,0);
  for (auto i = 0; i < n; i++) {
    char c;cin>>c;
    if (c<='9') val[i]=c-'0';
    else val[i]=c-'a'+11;
  }
  adj.assign(n,vi());
  for (auto i = 0; i < n-1; i++) {
    int x,y;cin>>x>>y;
    --x,--y;
    adj[x].emplace_back(y);
    adj[y].emplace_back(x);
  }
  for (auto i = 0; i < n; i++) {
    dfs(i,i,0);
  }
  cout<<sz(N)-1<<'\n';
}

