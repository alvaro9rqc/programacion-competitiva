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

const ll inf = 1e18;
struct Node {
  Node *l = 0, *r = 0;
  int lo, hi, vzer=0;
  ll l_udt=0, vmin=inf;
  Node(int _lo, int _hi) : lo(_lo), hi(_hi) {} // Large interval of −in f
  Node(vl& v, int _lo, int _hi) : lo(_lo), hi(_hi) {
    if (lo+1<hi){
      int mid = lo+(hi-lo) / 2;
      l = new Node(v,lo,mid);
      r = new Node(v,mid,hi);
      vmin=min(l->vmin, r->vmin);
    } else {
      vmin=v[lo];
    }
  }
  ll f_mi(int L, int R) {
    if(R<= lo or hi <= L) return inf;
    if (L <= lo and hi <= R) return vmin;
    push();
    return min(l->f_mi(L,R), r->f_mi(L,R));
  }
  void update(int L, int R, ll k) {
    if (R <= lo || hi <= L) return;
    if (L <= lo && hi <= R) {
      if (vmin>k) {
        vmin-=k;
        l_udt+=k;
        return;
      }
      if(lo+1<hi) {
        l_udt+=k;
        push();
        vmin=min(l->vmin, r->vmin);
        vzer = l->vzer+r->vzer;
      } else {
        vzer=1;
        vmin=inf;
        l_udt=0;
      }
    } else {
      push();
      l->update(L,R,k);
      r->update(L,R,k);
      vmin=min(l->vmin,r->vmin);
      vzer=l->vzer+r->vzer;
    }
  }
  void push() {
    if (!l) {
      int mid = lo + (hi - lo) / 2;
      l = new Node(lo, mid);
      r = new Node(mid, hi);
    }
    if (l_udt) {
      l->update(lo,hi, l_udt);
      r->update(lo,hi, l_udt);
      l_udt=0;
    }
  }
  ll f_z(int L, int R) {
    if (R <= lo || hi <= L) return 0;
    if (L <= lo && hi <= R) return vzer;
    push();
    // int mid = lo+(hi-lo)/2;
    return l->f_z(L,R) + r->f_z(L,R);
  }
  ll query(int L, int R, ll k) {
    ll ans = 0;
    while (k) {
      auto vm = f_mi(L,R);
      ll d = min(k,vm);
      k-=d;
      ans+= d*((R-L)-f_z(L,R));
      // dbg(f_z(L,R));
      // dbg(d);
      // dbg(vm);
      update(L,R,d);
    }
    return ans;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n;cin>>n;
  vl val(n);
  for(auto& i: val) cin >> i;
  Node lst(val, 0, n);
  int q;cin>>q;
  while(q--) {
    int l, r;ll k;cin>>l>>r>>k;
    --l;
    cout<<lst.query(l,r,k)<<'\n';
    // raya;
  }
}


