#include <bits/stdc++.h> 
using namespace std;

class UnionFind{
  private: 
    vector<int> p, rank, setSize;
    int numSets;
  public:
    UnionFind(int N) {
      p.assign(N, 0); 
      for (int i = 0; i < N; i++) 
        p[i] = i;
      rank.assign(N, 0);
      setSize.assign(N, 1);
      numSets = N;
    }

    int findSet(int i ) {
      return (p[i] == i) ? i : ( p[i] = findSet( p[i] ) );
    }

    bool isSameSet( int i, int j ) {
      return findSet(i) == findSet(j);
    }

    int numDisjointSets() {
      return numSets;
    }

    int sizeOfSet(int i) {
      return setSize [findSet(i)];
    }

    void unionSet(int i , int j) {
      if ( isSameSet(i, j) ) return;
      int x = findSet(i), y = findSet(j);
      if (rank[x] > rank[y]) swap(x, y);
      p[x] = y;
      if (rank[x] == rank[y]) ++rank[y];
      setSize[y] += setSize[x];
      --numSets;
    }
};

int main () {
  ios_base::sync_with_stdio(false);
  string line; 
  int m, n;
  while (cin >> n >> m) {
    getline(cin , line);
    if (n == 0 && m == 0) break;
    UnionFind uf (n);
    while (m --) {
      getline(cin , line);
      istringstream str(line);
      int s;
      int x, y;
      str >> s;
      if (s > 1) {
        str >> x;
        for (int i = 0; i < s-1; i++) {
          str >>y;
          uf.unionSet(y, x);
        }
      }
    }
    cout << uf.sizeOfSet(0) << '\n';
  }
  return 0;
}


