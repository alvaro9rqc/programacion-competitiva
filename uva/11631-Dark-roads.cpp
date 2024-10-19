#include <bits/stdc++.h> 
using namespace std;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;

class UnionFind {
  private:
    vi p, rank;
    
  public:
    UnionFind(int N) {
      p.assign(N, 0); for (int i = 0; i < N; ++i) {
        p[i]=i;
      }
      rank.assign(N,0);
    }

    int findSet(int i) {
      return (p[i]==i) ? i: (p[i] = findSet(p[i]));
    }

    bool isSameSet(int i, int j) {
      return findSet(i) == findSet(j);
    }

    void unionSet(int i, int j)  {
      if (isSameSet(i, j)) return;
      int x = findSet(i), y=findSet(j);
      if ( rank[x] > rank[y] ) swap(x,y);
      p[x] = y;
      if (rank[x] == rank[y]) ++rank[y];
    }
};

int main () {
  ios_base::sync_with_stdio(false);
  int m, n;
  while (cin >> m >> n) {
    if (m == 0 && n==0) break;
    vector<iii> el(n);
    int total = 0;
    for (int i = 0; i < n; ++i) {
      int u,v,w; cin >> u>>v>>w;
      el[i] = {w, u,v};
      total+= w;
    }
    sort(el.begin(), el.end());
    int mst = 0;
    int taken = 0;
    UnionFind uf(m);
    for(auto& [w, u, v]: el ) {
      if (uf.isSameSet(u,v)) continue;
      mst += w;
      uf.unionSet(u,v);
      ++taken;
      if ( taken == m -1) break;
    }
    cout << total - mst << '\n';
  }
  return 0;
}


