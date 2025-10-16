#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using vi = vector<int>;
using vl = vector<ll>;
#define dbg(x) cerr << #x << " = " << (x) << endl;
#define rep(i, a, b) for (auto i = a; i < (b); ++i)
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)

struct PushRelabel {
  struct Edge {
    int dest, back;
    ll f, c;
  };
  vector<vector<Edge>> g;
  vector<ll> ec;
  vector<Edge*> cur;
  vector<vi> hs; vi H;
  PushRelabel(int n):g(n), ec(n), cur(n), hs(2*n), H(n) {}
  void addEdge(int s, int t, ll cap, ll rcap=0) {
    if (s == t) return;
    g[s].push_back({t, sz(g[t]), 0, cap});
    g[t].push_back({s, sz(g[s])-1, 0, rcap});
  }
  void addFlow(Edge& e, ll f) {
    Edge &back = g[e.dest][e.back];
    if (!ec[e.dest] && f) hs[H[e.dest]].push_back(e.dest);
    e.f += f; e.c -= f; ec[e.dest] += f;
    back.f -= f; back.c += f; ec[back.dest] -= f;
  }
  ll calc(int s, int t) {
    int v = sz(g); H[s] = v; ec[t]=1;
    vi co(2*v); co[0] = v-1;
    rep(i, 0, v) cur[i]=g[i].data();
    for(Edge& e: g[s]) addFlow(e,e.c);
    for(int hi =0;;) {
      while(hs[hi].empty()) if (!hi--) return -ec[s];
      int u = hs[hi].back(); hs[hi].pop_back();
      while(ec[u]>0)
        if (cur[u] == g[u].data() + sz(g[u])) {
          H[u] = 1e9;
          for(Edge& e:g[u]) if (e.c && H[u] > H[e.dest]+1)
            H[u]=H[e.dest]+1, cur[u] = &e;
          if (++co[H[u]], !--co[hi] && hi < v) 
            rep(i,0,v) if (hi < H[i] && H[i] < v)
            --co[H[i]], H[i]=v+1;
          hi=H[u];
        } else if (cur[u]->c && H[u] == H[cur[u]->dest]+1)
          addFlow(*cur[u],min(ec[u], cur[u]->c));
        else ++cur[u];
    }
  }
  bool leftOfMinCut(int a) { return H[a]>=sz(g); }
  void intervalos(int m, vector<iii>&pares, int piv) {
    auto& li = g[m];
    set<ii> seg;
    for(auto& e: li) {
      if (e.f > 0) {
        int eid = e.dest - piv -1;
        auto& [l,r,p] = pares[eid];
        //cerr<<": " <<l<<' '<<r<<' '<<p<<'\n';
        if (e.f+p>=r) {
          seg.emplace(p,r);
          e.f-=r-p;
          p = l+int( e.f );
          seg.emplace(l, p);
        }else {
          seg.emplace(p, p+int(e.f));
          p+=int(e.f);
        }
      }
    }
    //ahora join
    //for(auto& [a,b]: seg) cerr<<a<<' '<<b<<'\n';
    auto it = seg.begin();
    auto [l, r] = *it;
    vector<ii> ans;
    while(1) {
      if (++it == seg.end()) { ans.emplace_back(l,r); break; }
      auto [nl, nr] = *it;
      if (r == nl) r = nr;
      else {
        ans.emplace_back(l, r);
        l = nl; r = nr;
      }
    }
    cout << format("{} ",sz(ans));
    for (auto i = 0; i < sz(ans); i++) {
      cout << format("({},{}){}", ans[i].first, ans[i].second, " \n"[i == sz(ans)-1]);
    }
  }
};


int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n, m;
  int casos = 0;
  while(1){
    int s = 0, t = 1, mono=1;
    int total =0;
    map<int, vi> mp;
    cin >> n;
    if (not n) break;
    cin >> m;
    PushRelabel pr(3*n+10);
    for (auto i = 0; i < n; i++) {
      int v, a, b; cin >> v >> a >> b;
      total+=v;
      ++mono;
      mp[a].emplace_back(mono);
      mp[b].emplace_back(-mono);
      pr.addEdge(s, mono, v);
    }
    set<int> mon(all(mp.begin()->second));
    int lf = mp.begin()->first;
    mp.erase(lf);
    int seg_id = mono;
    vector<iii> edgs;
    for(auto& [k, v]: mp) {
      //como era
      ++seg_id;
      edgs.emplace_back(lf, k, lf);
      //m-s
      int cap = k - lf;
      for(auto& i: mon) pr.addEdge(i, seg_id, cap);
      //s-t
      pr.addEdge(seg_id, t, cap*m);
      for(auto& i: v) {
        if (i < 0) mon.erase(-i);
        else mon.insert(i);
      }
      lf = k;
    }
    ll flow = pr.calc(s, t);
    cout << "Case "<<++casos;
    if (total == flow) {
      cout <<": Yes"  << '\n';
      for (auto i = 2; i <= mono; i++) {
        pr.intervalos(i, edgs, mono);
        //intervalos(i, pr.g[i])
        //int k = 0;
        //auto& li = pr.g[i];
        //for(auto& e: li) 
        //  if (e.f > 0) ++k;
        //cout << k <<" ";
        //int xd = 0;
        //for(auto& e: li) 
        //  if (e.f>0) {
        //    ++xd;
        //    int idx = e.dest - mono-1;
        //    cout <<format("({},{}){}", edgs[idx], edgs[idx]+e.f," \n"[xd==k]);
        //    edgs[idx]+=e.f;
        //  }
      }
    } else cout << ": No\n";
  }
}

