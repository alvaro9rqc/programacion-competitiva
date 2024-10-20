#include <bits/stdc++.h> 
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef tuple<int,int,int> iii;
typedef vector<ii> vii;

class UnionFind {
  private:
    vi p, rank;
  public:
    UnionFind(int N) {
      p.assign(N,0); for (int i = 0; i < N; ++i) {
        p[i] = i;
      }
      rank.assign(N,0);
    }
    int findSet(int i ) {
      return (p[i] == i) ? i:(p[i]=findSet(p[i]));
    }
    bool isSameSet(int i, int j) {
      return findSet(i) == findSet(j);
    }
    void unionSet(int i, int j) {
      if (isSameSet(i, j)) return;
      int x = findSet(i), y = findSet(j);
      if (rank[x] > rank[y]) swap(x,y);
      p[x] = y;
      if (rank[x] == rank[y]) ++rank[y];
    }
};

int main () {
  ios_base::sync_with_stdio(false);
  int n,m;
  while(cin>>n>>m) {
    if (n==0 && m==0) break;
    vector<iii> EL(m);
    UnionFind UF(n);
    for (int i = 0; i < m; ++i) {
      int u, v, w;
      cin >> u>>v>>w;
      EL[i] = {w,u,v};
    }
    sort(EL.begin(), EL.end());
    vi edges;
    for(auto& [w, u, v]: EL) {
      if (UF.isSameSet(u,v)) {
        edges.push_back(w);
        continue;
      }
      UF.unionSet(u,v);
    }
    if (edges.size() == 0) cout << "forest\n";
    else 
    {
      for (int i = 0; i < edges.size()-1; ++i) {
        cout << edges[i]<<' ';
      }
      cout << edges.back() << '\n';
    }
  }
  return 0;
}


