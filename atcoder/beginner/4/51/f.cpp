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

struct UF {
	vi e;
  vi v;
	UF(int n) : e(n, -1),v(n,0) {}
	bool sameSet(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
		return true;
	}
  int gv(int x) {return v[find(x)];}
  void sv(int x, int y) {v[find(x)]=y;}
};

vector<vi> adj;
vector<bool>col;
vi vis;

void dfs(int u, int id, bool c) {
  vis[u]=id;
  col[u]=c;
  for(auto& v: adj[u]) {
    if(vis[v]==id) continue;
    dfs(v,id,c^1);
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n,q;cin>>n>>q;
  adj.assign(n,vi());
  col.assign(n,0);
  vis.assign(n,-1);
  int ans = 0;
  UF unf(n);
  for (auto i = 0; i < n; i++) {
    int u,v;cin>>u>>v;
    if(ans==-1) {cout<< -1<<'\n';continue;}
    --u,--v;
    if(unf.sameSet(u,v)) {
      if((col[u]^(unf.gv(u)<0))==(col[v]^(unf.gv(v)<0))) {
        ans=-1;
        cout<< "-1\n";
      } else cout<<ans<<'\n';
      // dbg(unf.gv(u)<0);
      // dbg(unf.gv(v)<0);
      // dbg(col[col[u]]);
      // dbg(col[col[v]]);
    } else {
      if(unf.size(u)>unf.size(v))swap(u,v);
      int lans =0;
      auto vu=abs(unf.gv(u));
      auto vv=abs(unf.gv(v));
      ans-=vu+vv;
      bool inv=0;
      if((col[u]^(unf.gv(u)<0))==(col[v]^(unf.gv(v)<0))) { //mismo color
        auto x = vu+unf.size(v)-vv;
        auto y = vv+unf.size(u)-vu;
        if(x<y) lans=x; //original u
        else lans=y,inv=1;
        dfs(u,i,col[v]^1);
      } else {
        auto x = vu+vv;
        auto y = unf.size(v)+unf.size(u)-vu-vv;
        if(x<y)lans=x;
        else lans=y,inv=1;
      }
      // dbg(u+1);
      // dbg(v+1);
      // dbg(unf.gv(u));
      // dbg(unf.gv(v));
      // dbg(col[u]);
      // dbg(col[v]);
      // dbg(unf.size(u));
      // dbg(unf.size(v));
      // dbg(inv);
      unf.join(u,v);

      unf.sv(u,lans*((inv ^ (unf.gv(u)<0))?-1:1));
      ans+=lans;
      adj[u].emplace_back(v);
      adj[v].emplace_back(u);
      cout<<lans<<'\n';
    }
  }
}

