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

int n, q;
vi id, inp, out, tel, dis, root;
vi cicsz={0};
int csram=0;
vector<vi>adj;

void bfs(int u, int c) {
  queue<int> qu;
  qu.emplace(u);
  int d = 1;
  dis[u]=d;
  id[u]=-csram;
  root[u] = c;
  while(sz(qu)) {
    int lev = sz(qu);
    for (auto i = 0; i < lev; i++) {
      auto v = qu.front();
      id[v]=-csram;
      dis[v]=d;
      root[v]=c;
      qu.pop();
      for(auto& w: adj[v]) qu.emplace(w);
    }
    ++d;
  }
}

void fdc(int u, int d, int& t) {
  dis[u]=d;
  id[u] = -1;
  if (id[tel[u]] == 0) {
    fdc(tel[u], d+1, t);
  } else if (id[tel[u]] == -1) {
    t = tel[u];
    cicsz.emplace_back(dis[u]-dis[tel[u]]+1);
  } 
  if (t!=-1) id[u]= sz(cicsz)-1;
  else id[u] = -2;
  if (u == t) t = -1;
}

void her(int u, int& t) {
  inp[u] = t;
  for(auto& v: adj[u]) her(v, ++t); 
  out[u] = t++;
}

bool anc(int u, int v) {
  return inp[u]<=inp[v] and out[v]<=out[u];
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  cin >> n>>q;
  tel.assign(n,0);
  id.assign(n,0);
  inp.assign(n,0);
  out.assign(n,0);
  adj.assign(n,vi());
  dis.assign(n,0);
  root.assign(n,0);
  for (auto i = 0; i < n; i++) {
    int x; cin >> x; --x;
    tel[i] =x;
    adj[x].emplace_back(i);
  }
  int xd = -1;
  for (auto i = 0; i < n; i++) 
    if (not(id[i])) fdc(i, 1, xd);
  for (auto i = 0; i < n; i++) 
    if (id[i]>0 and sz(adj[i]) > 1) 
      for(auto& u: adj[i]) {
        xd = 0;
        if (id[u] < 0) ++csram, bfs(u, i), her(u, xd);
      }

  //for(auto& i: out) cout << i<<' ';cout <<'\n';
  //for(auto& i: inp) cout << i<<' ';cout <<'\n';
  for (auto q_ = 0; q_ < q; q_++) {
    int x, y; cin >> x >> y; --x,--y;
    if (id[x]>0) {
      if (id[x]==id[y]) cout << (dis[y]-dis[x]+cicsz[id[x]])%cicsz[id[x]]  <<'\n';
      else cout << -1 <<'\n';
    } else {
      if (id[y]<0) {
        if (id[y]==id[x] and anc(y, x)) cout << dis[x]-dis[y]<<'\n';
        else cout <<-1<<'\n';
      } else {
        if (id[y]==id[root[x]]) {
          xd = dis[x];
          x = root[x];cout << (dis[y]-dis[x]+cicsz[id[x]])%cicsz[id[x]]  + xd<<'\n';
        }
        else cout <<-1<<'\n';
      }
    }
  }
}


