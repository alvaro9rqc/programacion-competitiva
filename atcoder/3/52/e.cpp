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
    vll p, rank, setSize;
    ll numSets;
  public:
    UnionFind(ll N) {
      p.resize(N);
      iota(p.begin(), p.end(),0ll);
      rank.assign(N,0);
      setSize.assign(N,1);
      numSets=N;
    }
    ll findSet(ll i) {
      return (i == p[i])? i: ( p[i]=findSet(p[i]) );
    }
    ll isSameSet(ll i, ll j) {
      return findSet(i) == findSet(j);
    }
    ll numDSets() {
      return numSets;
    }
    ll sizeOfSets(ll i) {
      return setSize[ findSet(i) ];
    }
    void unionSet(ll i, ll j) {
      if (isSameSet(i,j)) return;
      ll x=findSet(i),y=findSet(j);
      if (rank[x] > rank[y]) swap(x,y);
      p[x]=y;
      if (rank[x] == rank[y]) ++rank[y];
      setSize[y] += setSize[x];
      --numSets;
    }
};

struct test {
  ll k;
  ll c;
  vll A;
};

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll N, M;
  cin >> N >> M;
  vector<test> conj(M);
  for (ll i = 0; i < M; ++i) {
    cin >> conj[i].k >> conj[i].c;
    conj[i].A.resize( conj[i].k );
    for(auto& e: conj[i].A) cin >> e, --e;
  }
  sort(conj.begin(), conj.end(), [](const auto& x,const auto& y ){
      return x.c < y.c;
      });
  //for(auto& st: conj) cout << st.c <<' ' << st.k <<'-';
  //cout << '\n';
  UnionFind uf(N);
  ll ans = 0;
  for(auto& stc: conj) {
    bool isf = false;
    for(auto& v: stc.A) {
      if (not uf.isSameSet(stc.A[0], v)) {
        ans += stc.c;
        uf.unionSet(stc.A[0], v);
      }
      if (uf.numDSets() == 1) {
        isf = true;
        break;
      }
    }
    if(isf) break;
  }
  if (uf.numDSets() == 1) cout << ans <<'\n';
  else cout << -1 <<'\n';
}


