#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;

typedef pair<ll, ll> ll_p; 
typedef tuple<ll, ll, ll> ll_t; 
typedef vector<ll> vll;
typedef vector<ll_p> vll_p;   
typedef vector<ll_t> vll_t;

class UnionFind {
  private:
    vi p, rank, setSize;
    vector<vi> m;
  public:
    UnionFind(int N) {
      p.resize(N);
      iota(p.begin(), p.end(), 0);
      rank.assign(N,0);
      setSize.assign(N,1);
      m.assign(N,vi());
      for (auto i = 0; i < N; ++i) {
        m[i].push_back(i);
      }
    }

    void q2(int u, int k) {
      if (k > sizeOfSet(u)) cout << -1<<'\n';
      else {
        int v = findSet(u);
        cout << m[v][--k]+1<<'\n';
      }
    }

    int findSet(int i) {
      return (p[i] == i)? i: (p[i] = findSet(p[i]));
    }

    bool isSameSet(int i, int j) {
      return findSet(i) == findSet(j);
    }

    int sizeOfSet(int i) {
      return setSize[findSet(i)];
    }

    void unionSet(int i, int j) {
      if(isSameSet(i,j)) return;
      int x = findSet(i);
      int y = findSet(j);
      if (rank[x] > rank[y]) swap(x,y);
      p[x] = y;
      vi v(min(10, int( m[x].size() + m[y].size() )));
      int px=0,py=0;
      int idx=0;
      while(idx < 10) {
        if ( m[x][px] > m[y][py] ) v[idx++] = m[x][px++];
        else v[idx++] = m[y][py++];
        if(py == m[y].size() or px == m[x].size() ) break;
      }
      while(idx < 10 and px < m[x].size()) v[idx++] = m[x][px++];
      while(idx < 10 and py < m[y].size()) v[idx++] = m[y][py++];
      m[y] = v;
      if ( rank[x] == rank[y] ) ++rank[y];
      setSize[y] += setSize[x];
    }

};

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int N,Q; cin>> N>>Q;
  UnionFind uf(N);
  for (auto i = 0; i < Q; ++i) {
    int q, v, k;
    cin >> q >> v >> k;
    if (q == 1) {
      uf.unionSet(--v,--k);
    } else uf.q2(--v, k);
  }
  return 0;
}


