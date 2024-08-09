#include <bits/stdc++.h> 
using namespace std;
typedef vector<int> vi;

class UnionFind {
  private: 
    vi p, rank, sizes;
  public:
    UnionFind(int n) {
      p.assign(n, 0);
      for (int i = 0; i < n; i++) p[i] = i;
      rank.assign(n, 0);
      sizes.assign(n, 1);
    }
    int findset(int i) {
      return (p[i] == i) ? i : ( p[i] = findset(p[i]) );
    }
    bool isSameSet(int i, int j) {
      return findset(i) == findset(j);
    }
    int size(int i) {
      return sizes[findset(i)];
    }
    void unionSet(int i, int j) {
      if (isSameSet(i, j)) return;
      int x = findset(i), y = findset(j);
      if (rank[x] > rank[y]) swap(x, y);
      p[x] = y;
      if (rank[x] == rank[y]) ++rank[y];
      sizes[y] += sizes[x];
    }
};

int main () {
  ios_base::sync_with_stdio(false);
  int T, N, M, i, j; 
  cin >> T;
  while (T--) {
    cin >> N >> M;
    int max = 1;
    UnionFind uf(N+1);
    while (M--) {
      cin >> i >> j;
      uf.unionSet(i, j);
      if (uf.size(i) > max) max = uf.size(i);
    }
    cout << max << '\n';
  }
  return 0;
}


