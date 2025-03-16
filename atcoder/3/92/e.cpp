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
    int numSets;
  public:
    UnionFind(int N): p(N), rank(N,0), setSize(N,1), numSets{N} {
      iota(p.begin(), p.end(), 0);
    }

    int findSet(int i) {
      return (i == p[i])? i: (p[i] = findSet(p[i]));
    }

    bool isSameSet(int i, int j) {
      return findSet(i) == findSet(j);
    }

    int sizeOfSet(int i) {
      return setSize[ findSet(i) ];
    }

    int numDS() {
      return numSets;
    }

    void unionSet(int i, int j) {
      int x=findSet(i), y=findSet(j);
      if ( rank[x] > rank[y] ) swap(x,y);
      p[x] = y;
      if (rank[x] == rank[y]) rank[y]++;
      setSize[y] += setSize[x];
      numSets--;
    }

};

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int N, M; cin >> N >> M;
  vector<tuple<int,int,int>> edges; // id , u, v
  UnionFind uf(N);
  for (auto i = 1; i <= M; ++i) {
    int x, y;
    cin >> x >> y;
    --x,--y;
    if (uf.isSameSet(x,y)) edges.emplace_back(i, x,y);
    else uf.unionSet(x,y);
  }
  unordered_set<int> vtx(N);
  for (auto v = 0; v < N; ++v) {
    vtx.insert( uf.findSet(v) );
  }
  int k = 0;
  vector<tuple<int,int,int>> ans;
  for(auto& [id, u, v]: edges) {
    if (uf.numDS() == 1) break;
    auto des = vtx.begin();
    if ( uf.isSameSet(*des, u) ) ++des;
    uf.unionSet(*des, v);
    ans.emplace_back(id, v, *des);
    vtx.erase( des );
    ++k;
  }
  cout << k <<'\n';
  for(auto& [id, ori, des]: ans) {
    cout << id <<' ' << ori+1 <<' ' << des+1 << '\n';
  }
}


