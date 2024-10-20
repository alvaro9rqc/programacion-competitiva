#include <bits/stdc++.h> 
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vector< tuple<int, int, int> > datos;
vi taken;

double dist(const int& u, const int& v) {
  double x = get<0>(datos[u]) - get<0>(datos[v]);
  double y = get<1>(datos[u]) - get<1>(datos[v]);
  return sqrt(x*x + y*y);
}

void process(const int& id,const double& prev_dist, priority_queue<tuple<double,int,double>> & pq ) {
  taken[id] = 1;
  for(int i = 0; i < datos.size(); ++i) {
    if (! taken[i]) {
      double d = dist(id, i);
      double w = max(d, prev_dist);
      pq.emplace(-d, -i, w);
    }
  }
}

int main () {
  int n;
  int counter=0;
  while (scanf("%d", &n)) {
    if (n == 0) break;
    datos.assign(n,{0,0,0});
    taken.assign(n, 0);
    for (int i = 0; i < n; ++i) {
      int x,y,m;
      scanf("%d %d %d", &x,&y,&m);
      datos[i] = {x,y,m};
    }
    priority_queue<tuple<double,int,double>> pq;
    double sum_sup = 0;
    double sum_low = get<2>(datos[0]);
    int num_taken = 0;
    process(0, 0, pq);
    while(! pq.empty()) {
      auto [w, u, d] = pq.top(); pq.pop();
      u = -u; w =-w;
      if ( taken[u] ) continue;
      //cout <<"--> "<< u << '\n';
      sum_sup+= get<2>(datos[u]) * d;
      sum_low +=get<2>(datos[u]); 
      process(u, d, pq);
      if (++num_taken == n-1) break;
    }
    printf("Island Group: %d Average %.2lf\n\n", ++counter, sum_sup/sum_low);
  }
  return 0;
}


