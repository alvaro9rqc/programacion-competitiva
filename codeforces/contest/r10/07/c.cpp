#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;

typedef pair<ll, ll> ll_p; 
typedef tuple<ll, ll, ll> ll_t; 
typedef vector<ll> vll;
typedef vector<ll_p> vll_p;   
typedef vector<ll_t> vll_t;
int N, S, E; 
vector<vi> g;
vector<bool> vis;
vi st;
void dfs(int u) {
  vis[u] = true;
  for(auto& v: g[u]) {
    if(not vis[ v ])
      dfs(v);
  }
  st.push_back(u);
}
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T; cin >> T;
  while(T--) {
    cin >> N>> S >> E;
    --S;
    --E;
    g.assign(N, vi());
    st.clear();
    vis.assign(N,false);
    for (int i = 0; i < N-1; ++i) {
      int u,v; cin >> u >> v;
      --u;
      --v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    dfs(E);
    for(auto& v: st) cout << v+1 <<' ';
    cout <<'\n';


  }
}


