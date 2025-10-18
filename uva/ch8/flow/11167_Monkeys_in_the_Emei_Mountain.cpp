#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ll> vl;

#define dbg(x) cerr << #x << " = " << (x) << endl;
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

struct PushRelabel {
  struct Edge {
    int dest, back;
    ll f, c;
  };
  vector<vector<Edge> > g;
  vector<ll> ec;
  vector<Edge*> cur;
  vector<vi> hs;
  vi H;

  PushRelabel(int n): g(n), ec(n), cur(n), hs(2*n), H(n) {}

  void addEdge(int s, int t, ll cap, ll rcap=0) {
    if (s == t) return;
    g[s].push_back(Edge{t, (int)g[t].size(), 0, cap});
    g[t].push_back(Edge{s, (int)g[s].size()-1, 0, rcap});
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
    for(size_t i=0;i<g[s].size();++i) addFlow(g[s][i],g[s][i].c);
    for(int hi =0;;) {
      while(hs[hi].empty()) if (!hi--) return -ec[s];
      int u = hs[hi].back(); hs[hi].pop_back();
      while(ec[u]>0) {
        if (cur[u] == g[u].data() + g[u].size()) {
          H[u] = 1000000000;
          for(size_t i=0;i<g[u].size();++i) {
            Edge &e = g[u][i];
            if (e.c && H[u] > H[e.dest]+1)
              H[u]=H[e.dest]+1, cur[u] = &e;
          }
          if (++co[H[u]], !--co[hi] && hi < v) {
            rep(i,0,v) if (hi < H[i] && H[i] < v)
              --co[H[i]], H[i]=v+1;
          }
          hi=H[u];
        } else if (cur[u]->c && H[u] == H[cur[u]->dest]+1)
          addFlow(*cur[u],min(ec[u], cur[u]->c));
        else ++cur[u];
      }
    }
  }

  bool leftOfMinCut(int a) { return H[a]>=sz(g); }

  void intervalos(int m, vector<iii>& pares, int piv) {
    vector<Edge>& li = g[m];
    set<ii> seg;
    for(size_t i=0;i<li.size();++i) {
      Edge &e = li[i];
      if (e.f > 0) {
        int eid = e.dest - piv -1;
        int l = get<0>(pares[eid]);
        int r = get<1>(pares[eid]);
        int p = get<2>(pares[eid]);
        if (e.f + p >= r) {
          seg.insert(ii(p, r));
          e.f -= (r - p);
          p = l + (int)(e.f);
          if (p-l)
            seg.insert(ii(l, p));
        } else {
          seg.insert(ii(p, p + (int)(e.f)));
          p += (int)(e.f);
        }
        get<2>(pares[eid]) = p;
      }
    }

    set<ii>::iterator it = seg.begin();
    int l = it->first, r = it->second;
    vector<ii> ans;
    while(true) {
      ++it;
      if (it == seg.end()) {
        ans.push_back(ii(l, r));
        break;
      }
      int nl = it->first, nr = it->second;
      if (r == nl) r = nr;
      else {
        ans.push_back(ii(l, r));
        l = nl; r = nr;
      }
    }

    printf("%d ", sz(ans));
    for (int i = 0; i < sz(ans); i++) {
      printf("(%d,%d)%c", ans[i].first, ans[i].second, (i == sz(ans)-1 ? '\n' : ' '));
    }
  }
};


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin.exceptions(cin.failbit);

  int n, m;
  int casos = 0;
  while(true){
    int s = 0, t = 1, mono=1;
    int total =0;
    map<int, vi> mp;
    cin >> n;
    if (!n) break;
    cin >> m;
    PushRelabel pr(3*n+10);
    for (int i = 0; i < n; i++) {
      int v, a, b; cin >> v >> a >> b;
      total+=v;
      ++mono;
      mp[a].push_back(mono);
      mp[b].push_back(-mono);
      pr.addEdge(s, mono, v);
    }

    set<int> mon(all(mp.begin()->second));
    int lf = mp.begin()->first;
    mp.erase(mp.begin());
    int seg_id = mono;
    vector<iii> edgs;

    for(map<int, vi>::iterator it = mp.begin(); it != mp.end(); ++it) {
      int k = it->first;
      vi &v = it->second;

      ++seg_id;
      edgs.push_back(iii(lf, k, lf));
      int cap = k - lf;
      for(set<int>::iterator i = mon.begin(); i != mon.end(); ++i)
        pr.addEdge(*i, seg_id, cap);
      pr.addEdge(seg_id, t, (ll)cap * m);
      for(size_t j=0;j<v.size();++j) {
        int i = v[j];
        if (i < 0) mon.erase(-i);
        else mon.insert(i);
      }
      lf = k;
    }

    ll flow = pr.calc(s, t);
    printf("Case %d", ++casos);
    if (total == flow) {
      printf(": Yes\n");
      for (int i = 2; i <= mono; i++) {
        pr.intervalos(i, edgs, mono);
      }
    } else {
      printf(": No\n");
    }
  }
}

