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

int N, K;
vector<vi> g;
vector<bool>vis;
vector<bool>selec;

int dfs(int i) {
  vis[i]=true;
  int c=0;
  for(auto& v: g[i]) {
    if (not vis[v]) c+=dfs(v);
  }
  return (c > 0 or selec[i])? c+1:0;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N >> K;
  g.resize(N);
  vis.assign(N,false);
  selec.assign(N,false);
  for (auto i = 0; i < N-1; ++i) {
    int a,b; cin >> a >> b;
    a--,--b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  int org;
  for (auto i = 0; i < K; ++i) {
    int v; cin >> v;
    selec[--v]=true;
    org = v;
  }
  cout << dfs(org) <<'\n';
}


