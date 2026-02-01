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

const ll inf = 1e16;
const ll mod =  998244353;

ll inv(ll b) {
  ll e = mod-2;
  ll r = 1;
  while(e) {
    if(e&1) r*=b, r%=mod;
    b*=b;
    b%=mod;
    e>>=1;
  }
  return r;
}

struct Node {
  Node *l = 0, *r = 0;
  ll lo, hi, mset = inf, madd = 0, val = 0;
  Node(ll _lo, ll _hi) : lo(_lo), hi(_hi) {} // Large interval of −in f
  Node(vl& v, ll _lo, ll _hi) : lo(_lo), hi(_hi) {
    if (lo + 1 < hi) {
      ll mid = lo + (hi - lo) / 2;
      l = new Node(v, lo, mid);
      r = new Node(v, mid, hi);
      // val = max(l->val, r->val);
      val = (l->val + r->val) %mod;
    } else {
      val = v[lo];
    }
  }
  ll query(ll L, ll R) {
    if (R <= lo || hi <= L) return 0;
    if (L <= lo && hi <= R) return val;
    push();
    // return max(l->query(L, R), r->query(L, R));
    //dbg(L);
    // dbg(R);
    // dbg((l->query(L,R) + r->query(L,R))%mod);
    return (l->query(L,R) + r->query(L,R))%mod;
  }
  void set(ll L, ll R, ll x) {
    if (R <= lo || hi <= L) return;
    if (L <= lo && hi <= R) {
      mset = x;
      val = ((hi-lo)*x)%mod;
      madd = 0;
    } else {
      push();
      l->set(L, R, x);
      r->set(L, R, x);
      // val = max(l->val, r->val);
      val = (l->val + r->val) %mod;
    }
  }
  void add(ll L, ll R, ll x) {
    if (R <= lo || hi <= L) return;
    if (L <= lo && hi <= R) {
      if (mset != inf) mset += x;
      else madd += x;
      val += x;
    } else {
      push();
      l->add(L, R, x);
      r->add(L, R, x);
      val = max(l->val, r->val);
    }
  }
  void push() {
    if (!l) {
      ll mid = lo + (hi - lo) / 2;
      l = new Node(lo, mid);
      r = new Node(mid, hi);
    }
    if (mset != inf) {
      l->set(lo, hi, mset);
      r->set(lo, hi, mset);
      mset = inf;
    } 
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n, m;
  cin >> n>>m;
  vl arr(n); for(auto& i: arr) cin>>i;
  Node lst(arr, 0, n);
  for (auto _ = 0; _ < m; _++) {
    int l, r; cin >> l >> r;
    --l;
    auto s = lst.query(l,r);
    //dbg(s);
    s = s * inv(r-l);
    s%=mod;
    //dbg(s);
    lst.set(l,r,s);
    //raya;
  }
  for (auto i = 0; i < n; i++) {
    cout << lst.query(i,i+1)<<' ';
  }
  cout<<'\n';
}

