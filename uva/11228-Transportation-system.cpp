#include <bits/stdc++.h> 
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vii datos;
vi taken;

double dist(int u, int v) {
  int x = datos[u].first - datos[v].first;
  int y = datos[u].second - datos[v].second;
  return sqrt(x*x + y*y);
}

void process(int u, priority_queue<pair<double, int>>& pq) {
  taken[u] = 1;
  for (auto i = 0; i < datos.size(); ++i) {
    if (! taken[i]) pq.emplace(-dist(u, i), -i);
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  int t, n;
  double r;
  int counter = 0;
  cin >> t;
  while (counter++ < t) {
    priority_queue<pair<double, int>> pq;
    cin >> n >> r;
    datos.assign(n, pair<double, int>());
    for (auto i = 0; i < n; ++i) {
      cin >> datos[i].first >> datos[i].second;
    }
    taken.assign(n, 0);
    process(0,pq);
    double sho, lan;
    sho=lan=0;
    int states = 1;
    int num_taken = 0;
    while(! pq.empty()) {
      auto [w, u] = pq.top(); pq.pop();
      w = -w; u = -u;
      if (taken[u]) continue;
      if (w > r) 
      {
        lan+=w;
        states++;
      }
      else sho+=w;
      process(u,pq);
      if(++num_taken == n-1) break;
    }
    cout << "Case #"<<counter<<": "<<states<<' '<<round(sho)<<' '<<round(lan)<<'\n';
  }
  return 0;
}
