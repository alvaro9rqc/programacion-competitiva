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
vi parent;
vector<vl> mtx;

ll bfs(int s, int t) {
  parent.assign(sz(adj),-1);
  parent[s]=-2;
  queue<pair<int,ll>> qu;
  //qu.emplace(s, inf);
  for(auto& v: adj[s]) {
    if (mtx[s][v]!=1) {
      qu.emplace(v, mtx[s][v]);
      parent[v] = s;
    }
  }
  while(sz(qu)) {
    auto [cur, flow] = qu.front(); qu.pop();
    for(auto& v: adj[cur]) {
      if (parent[v]==-1 and mtx[cur][v]!=1) {
        parent[v] =  cur;
        ll nflow = gcd(flow, mtx[cur][v]);
        //dbg(cur);
        //dbg(v);
        //dbg(flow);
        //dbg(nflow);
        if (v==t) return nflow;
        qu.emplace(v, nflow);
      }
    }
  }
  return 1;
}



inline ll add(ll n) {
  ll ans = 0;
  for (auto i = 2; i*i <= n; i++) {
    while(n % i == 0) {
      ++ans;
      n/=i;
    }
  }
  if (n!=1) ++ans;
  return ans;
}

ll maxflow(int s, int t) {
  ll flow = 0;
  ll nflow;
  while((nflow = bfs(s,t))!=1) {
    //dbg(nflow);
    flow += add(nflow);
    int cur = t;
    while(cur!=s) {
      int prev = parent[cur];
      mtx[prev][cur] /= nflow;
      mtx[cur][prev] *= nflow;
      cur=prev;
    }
  }
  return flow;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n; cin >> n;
  int m; cin >> m;
  //vector<vi> adj(n+2);
  adj.assign(n+2, vi());
  vi arr(n+1);
  mtx.assign(n+2, vl(n+2, 1));
  for (auto i = 1; i <= n; i++) {
    cin >> arr[i];
    if ((i&1)==0) {
      adj[n+1].emplace_back(i), mtx[i][n+1]=arr[i];
      adj[i].emplace_back(n+1);
    }
    else {
      adj[0].emplace_back(i);
      adj[i].emplace_back(0);
      mtx[0][i]=arr[i];
    }
  }
  for (auto i = 0; i < m; i++) {
    int x,y; cin >> x >> y;
    if(y&1) swap(x,y);
    adj[x].emplace_back(y);
    adj[y].emplace_back(x);
    mtx[x][y]=gcd(arr[x],arr[y]);
  }
  cout << maxflow(0, n+1)<<'\n';
}

