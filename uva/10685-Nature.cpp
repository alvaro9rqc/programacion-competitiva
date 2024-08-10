#include <bits/stdc++.h> 
using namespace std;
typedef vector<int> vi;

class UnionFind {
  private:
    vi p, rank, len;
  public:
    UnionFind(int n) {
      p.assign(n, 0);
      for (int i = 0; i < n; i++) {
        p[i] = i;
      }
      rank.assign(n, 1);
      len.assign(n, 1);
    }
    int findSet(int i) {
      return (p[i] == i)? i: ( p[i] = findSet(p[i]) );
    }
    bool isSameset(int i, int j) {
      return findSet(i) == findSet(j);
    }
    int sizeSet(int i) {
      return len[findSet(i)];
    }
    void unionSet(int i, int j) {
      if (findSet(i) == findSet(j) ) return;
      int x = findSet(i), y = findSet(j);
      if (rank[x] > rank[y]) swap(x, y);
      p[x] = y;
      if (rank[x] == rank[y]) rank[y]++;
      len[y] += len[x];
    }
};

int main () {
  ios_base::sync_with_stdio(false);
  int C, R; 
  string w1, w2;
  while (true) {
    cin >> C >> R;
    if (C == R && R == 0) break;
    unordered_map<string, int> m (C);
    UnionFind uf(C);
    while (C --) {
      cin >> w1;
      m[w1] = C;
    }
    int len = 1;
    while (R--) {
      cin >> w1 >> w2;
      uf.unionSet( m[w1], m[w2] );
      if (uf.sizeSet(m[w2]) > len) len = uf.sizeSet( m[w2] );
    }
    cout << len << '\n';
  }
  return 0;
}


