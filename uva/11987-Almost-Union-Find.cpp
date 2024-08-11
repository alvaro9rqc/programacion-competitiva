#include <bits/stdc++.h> 
using namespace std;
typedef vector<int> vi;

class UnionFind {
  private:
    vi p, rank, setSize, sum;
    vector< unordered_set<int> > childs;
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
      childs.assign(n, unordered_set<int>());
      setSize.assign(n, 1);
    }

    int findSet(int i) {
      return (p[i] == i) ? i: ( p[i] = findSet(p[i]) );
    }

    bool isSameSet(int i, int j) {
      return findSet(i) == findSet(j);
    }

    int sizeOfSet(int i) {
      return setSize[findSet(i)];
    }

    int sumSet(int i) {
      return sum[ findSet(i) ];
    }

    void unionSet(int i , int j) {
      if ( isSameSet(i, j) ) return;
      int x = findSet(i), y = findSet(j);
      if (rank[x] > rank[y]) swap(x, y);
      p[x] = y;
      childs[y].insert(x);
      if (rank[x] == rank[y]) rank[y]++;
      setSize[y] += setSize[x];
      sum[y] += sum[x];
    }

    void moveToSet(int i, int j) {
      if ( isSameSet(i, j) ) return;
      setSize[ findSet(i) ]--;
      sum[findSet(i)] -= i;
      int lastChild = -1;
      for ( auto it = childs[i].begin(); it != childs[i].end(); ++it ) {
        if ( isSameSet(i, *it) ) lastChild = *it;
        else childs[i].erase(*it);
      }
      if (p[i] == i && lastChild != -1) {
        for ( auto it = childs[i].begin(); it != childs[i].end(); ++it ) {
          p[*it] = lastChild;
        }
      }
      childs[i].clear();
      p[i] = i;
      unionSet(i, j);
    }
}

int main () {
  ios_base::sync_with_stdio(false);

  return 0;
}


