#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
#define dbg(x) cerr << #x << " = " << (x) << endl;
#define raya cerr << " ==================== " << endl;
#define rep(i, a, b) for (auto i = a; i < (b); ++i)
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)

struct Node {
  typedef int T;
  static constexpr T unit = 0;
  static T f(T a, T b) { return a+b; }
  Node *l = 0, *r = 0;
  int lo, hi;
  T val = unit;
  Node(int _lo, int _hi, T _val = unit) : lo(_lo), hi(_hi), val(_val) {}
  Node(Node* _l, Node* _r) : l(_l), r(_r), lo(_l->lo), hi(_r->hi) {
    val = f(l->val, r->val);
  }
  Node(const vector<T>& v, int _lo, int _hi) : lo(_lo), hi(_hi) {
    if (lo + 1 < hi) {
      int mid = lo + (hi - lo) / 2;
      l = new Node(v, lo, mid);
      r = new Node(v, mid, hi);
      val = f(l->val, r->val);
    } else {
      val = v[lo];
    }
  }
  T query(int L, int R) {
    if (R <= lo || hi <= L) return unit;
    if (L <= lo && hi <= R) return val;
    return f(l->query(L, R), r->query(L, R));
  }
  Node* update(int pos, T x) {
    if (lo + 1 == hi) return new Node(lo, hi, x);
    int mid = lo + (hi - lo) / 2;
    if (pos < mid) return new Node(l->update(pos, x), r);
    else return new Node(l, r->update(pos, x));
  }
};

#include <bits/extc++.h>
// To use most b i t s rather than j u s t the lowest ones :
struct chash { // large odd number for C
  uint64_t C = ll(4e18 * acos(0)) | 71;
  ll operator()(ll x) const { return __builtin_bswap64(x*C); }
};
// __gnu_pbds::gp_hash_table<ll,int,chash> h({},{},{},{},{1<<16});
using h_m = __gnu_pbds::gp_hash_table<int,int,chash>;

void solve() {
  int n,q;cin>>n>>q;
  h_m ump;
  vi arr(n); for(auto& i: arr) cin >> i,ump[i]=0;
  vi brr;
  for(auto& [k,v]: ump) brr.emplace_back(k);
  sort(all(brr));
  int m = sz(brr);
  for (auto i = 0; i < m; i++) ump[brr[i]]=i;
  vector<Node*> vrr;
  vi srr(m);
  vrr.emplace_back(new Node(srr,0,m));
  for (auto i = 0; i < n; i++){
    auto idx = ump[arr[i]];
    vrr.emplace_back(vrr[i]->update(idx, ++srr[idx]));
  }
  for (auto _ = 0; _ < q; _++) {
    int l, r,k;cin>>l>>r>>k;
    auto nl=vrr[l-1],nr=vrr[r];
    while(nl->lo != nl->hi-1) {
      auto d = nr->l->val-nl->l->val;
      if(k>d) {
        k-=d;
        nr=nr->r;
        nl=nl->r;
      } else {
        nr=nr->l;
        nl=nl->l;
      }
    }
    cout<< brr[nl->lo]<<'\n';
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt=1;
  // cin>>tt;
  while(tt--) {
    solve();
  }
}

