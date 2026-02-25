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
struct Node {
  Node *l = 0, *r = 0;
  ll lo, hi, ladd = 0, valsum = 0, valmin = inf;
  Node(ll _lo, ll _hi) : lo(_lo), hi(_hi) {} // Large interval of −in f
  Node(vl& v, ll _lo, ll _hi) : lo(_lo), hi(_hi) {
    if (lo + 1 < hi) {
      ll mid = lo + (hi - lo) / 2;
      l = new Node(v, lo, mid);
      r = new Node(v, mid, hi);
      valmin = min(l->valmin, r->valmin);
      valsum = l->valsum+r->valsum;
    } else {
      valsum = v[lo];
      valmin = v[lo];
    }
  }
  ll querymin(ll L, ll R) {
    if (R <= lo || hi <= L) return inf;
    if (L <= lo && hi <= R) return valmin;
    push();
    return min(l->querymin(L, R), r->querymin(L, R));
  }
  ll querysum(ll L, ll R) {
    //cerr<<format("-> L:{} R:{}, lo {}, hi {} sum{} min{}\n", L,R,lo,hi,valsum,valmin);
    //cerr<<"-> "<<a+b<<'\n';
    if (R <= lo || hi <= L) return 0;
    if (L <= lo && hi <= R) {
      cerr<<format("qsum L:{} R:{}, lo {}, hi {} sum{} min{}\n", L,R,lo,hi,valsum,valmin);
      return valsum;
    }
    push();
    auto a = l->querysum(L,R);
    if (a>=inf)a=0;
    auto b = r->querysum(L,R);
    if (b>=inf)b=0;
    //cerr<<format("ans L:{} R:{}, lo {}, hi {} sum{} min{} a: {} b: {}\n", L,R,lo,hi,valsum,valmin,a,b);
    return a+b;
  }
  //void set(int L, int R, int x) {
  //  if (R <= lo || hi <= L) return;
  //  if (L <= lo && hi <= R) {
  //    mset = val = x;
  //    madd = 0;
  //  } else {
  //    push();
  //    l->set(L, R, x);
  //    r->set(L, R, x);
  //    val = max(l->val, r->val);
  //  }
  //}
  void add(ll L, ll R, ll k) {
    if (R <= lo || hi <= L) return;
    if (L <= lo && hi <= R) {
      //auto m = this->querymin(L,R);
      if (valmin == inf) return;
      if(lo+1==hi){
        ladd=0;
        valsum=max(valsum-k,0ll);
        valmin = (valmin-k>0?valmin-k:inf);
        cerr<<format("ones add L:{} R:{}, lo {}, hi {} sum{} min{} k: {}\n", L,R,lo,hi,valsum,valmin, k);
        return;
      }
      auto lm = l->valmin;
      auto rm = r->valmin;
      if (k < lm and k < rm and lm != inf and rm != inf){
        ladd+=k;
        valmin-=k;
        valsum-=k*(hi-lo);
      } else {
        push();
        l->add(L,R,k);
        r->add(L,R,k);
        valmin=min(l->valmin, r->valmin);
        valsum=l->valsum + r->valsum;
      }
    } else {
      push();
      l->add(L, R, k);
      r->add(L, R, k);
      valsum = l->valsum+r->valsum;
      valmin = min(l->valmin, r->valmin);
    }
    //cerr<<format("L:{} R:{} sum{} min{}\n", L,R,valsum,valmin);
    cerr<<format("add L:{} R:{}, lo {}, hi {} sum{} min{} k: {}\n", L,R,lo,hi,valsum,valmin,k);
  }
  void push() {
    if (!l) {
      ll mid = lo + (hi - lo) / 2;
      l = new Node(lo, mid);
      r = new Node(mid, hi);
    }
    if (ladd!=0) {
      l->add(lo,hi,ladd);
      r->add(lo,hi,ladd);
      ladd=0;
    }
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n; cin >> n;
  vl arr(n); for(auto& i: arr) cin >> i;
  Node lsg(arr, 0, n);
  int q; cin >> q;
  for (auto i = 0; i < q; i++) {
    int l, r, k; cin>> l >> r >> k;
    --l;
    auto s1 = lsg.querysum(l,r);
    //cerr<<"\n\n";
    lsg.add(l,r,k);
    //cerr<<"\n\n";
    auto s2 = lsg.querysum(l,r);
    //dbg(s1);
    //dbg(s2);
    cout << (s1 - s2) <<'\n';
    //raya;
  }
}


