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

const ll INF = LLONG_MAX;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll N, M; cin >> N >> M;
  vll A(N);
  vector<vll_p> g(N);
  for(auto& v: A) {
    cin >> v;
  }
  for (auto i = 0; i < M; ++i) {
    ll u,v,b; 
    cin >> u >> v >> b;
    --u,--v;
    g[u].emplace_back(v,b);
    g[v].emplace_back(u,b);
  }
  ll ans = 0;
  vll dist(N, INF);
  dist[0]=A[0];
  priority_queue<ll_p,vll_p,greater<ll_p>> pq;
  pq.emplace(A[0],0);
  while(not pq.empty()) {
    auto [w,v] = pq.top(); pq.pop();
    if (w > dist[v]) continue;
    dist[v] = w;
    for(auto& [u, d]: g[v]) {
      if (w+d+A[u] < dist[u])
        pq.emplace(w+d+A[u],u );
    }
  }
  for (auto i = 1; i < N; ++i) {
    cout << dist[i] <<' ';
  }
  cout <<'\n';
}
