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

vi visited;
vll val;
vector<vll_p> g;

void dfs(int i, ll n) {
  visited[i] = 1;
  val[i] = n;
  for(auto& [u,w]: g[i]) {
    if(!visited[u]) dfs(u,val[i] + w);
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll N, M; cin >> N >> M;
  g.assign(N,vll_p());
  for (ll i = 0; i < M; ++i) {
    ll u, v, w; cin >> u >> v >> w;
    g[--u].emplace_back(--v, w);
    g[v].emplace_back(u, -w);
  }
  visited.assign(N,0);
  val.resize(N);
  for (ll i = 0; i < N; ++i) {
    if (! visited[i]) {
      dfs(i,0);
    }
  }
  for(auto& i: val) {
    cout << i << ' ';
  }
  cout << '\n';
  return 0;
}


