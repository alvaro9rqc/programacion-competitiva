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

  struct Edge {
    int dest, back;
    ll f, c;
  };
struct PushRelabel {
  vector<vector<Edge>> g;
  vector<ll> ec;
  vector<Edge*> cur;
  vector<vi> hs; vi H;
  PushRelabel(int n): g(n), ec(n), cur(n), hs(2*n), H(n) {}
  
  void addEdge(int s, int t, ll cap, ll rcap=0) {
    if (s == t) return ;
    g[s].push_back({t, sz(g[t]), 0, cap});
    g[t].push_back({s,sz(g[s])-1, 0, rcap});
  }

  void addFlow(Edge& e, ll f) {
    Edge &back = g[e.dest][e.back];
    if (!ec[e.dest] && f) hs[H[e.dest]].push_back(e.dest);
    e.f += f; e.c -= f; ec[e.dest] +=f;
    back.f -= f; back.c += f; ec[back.dest]-=f;
  }
  ll calc(int s, int t) {
    int v = sz(g); H[s] = v; ec[t] = 1;
    vi co(2*v); co[0]=v-1;
    rep(i, 0,v) cur[i]=g[i].data();
    for (Edge& e:g[s]) addFlow(e,e.c);

    for (int hi = 0;;) {
      while(hs[hi].empty()) if (!hi--) return -ec[s];
      int u = hs[hi].back(); hs[hi].pop_back();
      while(ec[u]>0)
        if (cur[u] == g[u].data() +sz(g[u])) {
          H[u] = 1e9;
          for(Edge& e: g[u]) if (e.c && H[u] > H[e.dest]+1)
            H[u]=H[e.dest]+1, cur[u]=&e;
          if (++co[H[u]], !--co[hi]&&hi<v)
            rep(i,0,v) if (hi < H[i] && H[i] < v) 
              --co[H[i]], H[i]=v+1;
          hi = H[u];
        } else if (cur[u]->c && H[u] == H[cur[u]-> dest]+1)
          addFlow(*cur[u], min(ec[u], cur[u]->c));
        else ++cur[u];
    }
  }
  bool leftOfMinCut(int a) { return H[a]>=sz(g); }
};

vi st;
set<ii> used;

void dfs(int u, vector<vector<Edge>>& g, int tgt) {
  st.emplace_back(u);
  //dbg(u);
  if (u == tgt) {
    cout << sz(st)<<'\n';
    for(auto& v: st) cout << v+1 << ' ';
    cout <<'\n';
  } else {
    for(auto& edg: g[u]) {
      if ( edg.f==1 and not used.count({u, edg.dest})) {
        used.emplace(u, edg.dest), dfs(edg.dest, g, tgt); 
        break;
      }
    }
  }
  st.pop_back();
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n, m;
  cin >> n >> m;
  PushRelabel pr(n);
  for (auto i = 0; i < m; i++) {
    int x, y; cin >> x >> y;
    --x,--y;
    pr.addEdge(x,y,1,0);
  }
  int xd = pr.calc(0, n-1);
  cout << xd<<'\n';
  //for (auto i = 0; i < sz(pr.g); i++) { cout << i <<"++\n"; for(auto& e: pr.g[i]) cout << e.dest << ' '<<e.f<<' '<<e.c<<' '<<'\n'; }
  //raya;
  st.emplace_back(0);
  for(auto& e: pr.g[0]) {
    if (e.f == 1)
      used.emplace(0, e.dest),dfs(e.dest, pr.g, n-1);
  } 
}

