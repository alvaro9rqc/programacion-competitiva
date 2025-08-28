#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
#define endl '\n'
#define dbg(x) cerr << #x << " = " << (x) << endl;
#define raya cerr << " ==================== " << endl;
#define rep(i, a, b) for (auto i = a; i < (b); ++i)
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)

int n;
vector<vi> adj;
vector<bool>vis;
vi path;

int larg(int u, int& v) {
  vis[u] =1;
  int d= 0;
  int x = u;
  v= x; 
  for(auto& w: adj[u]) {
    if (vis[w]) continue;
    int d2 = larg(w, x);
    if (d2 > d) d=d2,v=x;
  }
  return d+1;
}

int diam(int u) {
  vis[u] =1;
  int d = 0;
  int x = -1;
  for(auto& v: adj[u]) {
    if (not vis[v]) {
      int d2 = diam(v);
      if (d2>d) d=d2, x=v;
    }
  }
  path[u]=x;
  return d+1;
}

vi st;

void sta(int u) {
  vis[u] = 1;
  st.emplace_back(u);
  if (path[u] !=-1) vis[path[u]]=1;
  for(auto& v: adj[u]) {
    if (vis[v]) continue;
    sta(v);
  }
  if(path[u]!=-1) sta(path[u]);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt; cin >> tt;
  while(tt--) {
    cin >> n;
    adj.assign(n, vi());
    for (auto i = 0; i < n-1; ++i) {
      int x, y; cin >> x >> y;
      --x, --y;
      adj[x].emplace_back(y);
      adj[y].emplace_back(x);
    }
    vis.assign(n,0);
    int v=0;
    larg(0,v);
    path.assign(n,-1);
    vis.assign(n,0);
    diam(v);
    st.clear();
    vis.assign(n,0);
    sta(v);
    int xd = 0;
    vi deg(n);
    for (auto i = 0; i < n; i++) 
      deg[i] = sz(adj[i]);
    for (auto i = 2; i < n; i++) {
      if (deg[st[i-1]]>2) {
        xd=1;
        cout << st[i-2]+1<<' '<<st[i-1]+1<<' '<<st[i]+1<<'\n';
        //deg[st[i]]+=deg[st[i-1]]-2;
        break;
      }
    }
    if (not xd) cout <<-1<<'\n';
    //for(auto& ei: st) cout << ei <<' ';
    //cout <<'\n';
  }
}


