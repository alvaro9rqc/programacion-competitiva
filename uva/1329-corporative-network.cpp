#include <bits/stdc++.h> 
using namespace std;
typedef vector<int> vi;

enum {
  UNVISITED = -1,
  VISITED = -2
};

void dfs (vector<vi>& g, vi& w, vi& vs, int o, int p) {
  vs[o] = VISITED;
  w[o] += p;
  for (int v : g[o]) {
    if (vs[v] == UNVISITED) {
      dfs(g, w, vs, v, p);
    }
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  int T, N, I, J; 
  char A;
  string line;
  cin >> T;
  while (T--) {
    cin >> N;
    vector<vi> g(N+1, vi());
    vi ws(N+1, 0);
    while (true){
    //while (getline(cin, line)){
      //cout << line << "-\n"; 
      //if (line[0] == 'O') break;
      //istringstream buff(line);
      cin >> A; 
      //cout << "->" << A << "<-\n";
      if (A == 'O') break;
      if (A == 'E') {
        cin >> I;
        //cout << uf.getLen(--I) << '\n';
        cout << ws[I] << '\n';
      } else {
        cin >> I >> J;
        g[J].push_back(I); //I could cause problems, for repeated data
        int plus = abs(I - J) % 1000 + ws[J];
        vi arr(g.size(), UNVISITED);
        dfs(g, ws, arr, I, plus);
        //uf.unionSet(--I, --J);
      }
    }
  }
  return 0;
}


