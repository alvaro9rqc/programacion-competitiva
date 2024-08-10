#include <bits/stdc++.h> 
using namespace std;
typedef vector<int> vi;

class UnionFind {
  private:
    vi p, rank, setSize, sum;
    int sets;
  public:
    UnionFind(int n) {
      p.assign(n, 0);
      sum.assign(n, 0);
      for (int i = 0; i < n; ++i)
      {
        sum[i] = i;
        p[i] = i;
      }
      rank.assign(n, 0);
      setSize.assign(n, 1);
      sets = n;
    }

    int findSet(int i) {
      return (p[i] == i) ? i: ( p[i] = findSet(p[i]) );
    }

    bool isSameSet(int i, int j) {
      return findSet(i) == findSet(j);
    }

    int numDisjointSets() {
      return sets;
    }

    int sizeOfSet(int i) {
      return setSize[findSet(i)];
    }

    void unionSet(int i , int j) {
      if ( isSameSet(i, j) ) return;
      int x = findSet(i), y = findSet(j);
      if (rank[x] > rank[y]) swap(x, y);
      p[x] = y;
      if (rank[x] == rank[y]) rank[y]++;
      setSize[y] += setSize[x];
      sum[y] += sum[x];
      sets--;
    }
}

int main () {
  ios_base::sync_with_stdio(false);
   
  return 0;
}


