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

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll N, M,X; cin >>N>>M>>X;
  vector<vll> g(N);
  vector<vll> gp(N);
  for (ll i = 0; i < M; ++i) {
    ll u, v; cin >>u>>v;
    --u;--v;
    g[u].push_back(v);
    gp[v].push_back(u);
  }
  const ll INF = LLONG_MAX;
  vll dist(N, INF);
  vll distp(N, INF);
  priority_queue<tuple<ll,ll,bool>, vector<tuple<ll,ll,bool>>, greater<tuple<ll,ll,bool>>> pq;
  dist[0]=0;
  distp[0]=0;
  pq.emplace(0,0,false);
  while(not pq.empty()) {
    auto[d,v,p]=pq.top(); pq.pop();
    vector<vll>* g_o = &g;
    vector<vll>* g_al = &gp;
    auto* d_o = &dist;
    auto* d_al = &distp;
    if(p) {
      swap(g_o, g_al);
      swap(d_o,d_al);
    }
    if( (not p and d > dist[v] ) or (p and d > distp[v]) )
      continue;
    if(v==N-1) {
      cout << d <<'\n';
      return 0;
    }
    for(auto& u: (*g_o)[v]) {
      if ( d + 1 < (*d_o)[u] ) {
        (*d_o)[u]=d+1;
        pq.emplace(d+1,u,p);
      }
    }
    for(auto& u: (*g_al)[v]) {
      if(d+X+1 < (*d_al)[u]) {
        (*d_al)[u]=d+X+1;
        pq.emplace(d+X+1, u, not p);
      }
    }
  }
}


