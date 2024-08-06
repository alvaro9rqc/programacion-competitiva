#include <bits/stdc++.h> 
using namespace std;
class UnionFind {
  private:
    vector<int> p, rank, len;
  public:
    UnionFind(int n) {
      p.assign(n, 0);
      for (int i = 0; i < p.size(); i++)
        p[i] = i;
      rank.assign(n, 0);
      len.assign(n, 0);
    }

    int findSet(int n) {
      return (p[n] == n) ? n : ( p[n] = findSet(p[n]) );
    }

    bool isSameSet(int i, int j) {
      return findSet(i) == findSet(j);
    }

    int getLen(int i ) {
      return len[ findSet(i) ];
    }

    void unionSet(int i, int j) {
      if ( isSameSet(i,j) ) return;
      int x = findSet(i), y = findSet(j); //I could cause sombre problems
      if (rank[x] > rank[y]) swap(x, y);
      p[x] = y;
      if (rank[x] == rank[y]) ++rank[y];
      len[y] += len[x] + ( abs(i - j) % 1000 );
    }

};

int main () {
  ios_base::sync_with_stdio(false);
  int T, N, I, J; 
  char A;
  string line;
  cin >> T;
  while (T--) {
    cin >> N;
    UnionFind uf(N);
    while (getline(cin, line)){
      if (line[0] == '0') break;
      istringstream buff(line);
      cin >> A; 
      if (A == 'E') {
        cin >> I;
        cout << uf.getLen(--I) << '\n';
      } else {
        cin >> I >> J;
        uf.unionSet(--I, --J);
      }
    }
  }
  return 0;
}


