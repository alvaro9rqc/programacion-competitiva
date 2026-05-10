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

struct T{
  array<multiset<ll>,3> v;
  int n,m;
  ll sum = 0;
  void u(int i, ll s) {
    if(i==0 or i==2) sum+=s;
  }
  ll op(ll del, ll ins) {
    int d = 0;
    for ( ; d < 3; ++d) {
      auto it = v[d].find(del);
      if(it!=v[d].end()) {
        v[d].erase(it);
        break;
      }
    }
    // if(d==0 or d == 2) sum-=del;
    u(d,-del);
    int i = 2;
    for (; i >= 0; i--) {
      if(i==0 or (sz(v[i]) and *(v[i].begin()) <= ins )) {
        v[i].emplace(ins);
        break;
      }
    }
    // if(i==0 or i==2) sum+=ins;
    u(i,ins);
    while(i!=d) {
      if(i<d) {
        auto it = v[i].end();
        --it;
        v[i+1].emplace(*it);
        u(i,-*it);
        u(i+1,*it);
        v[i].erase(it);
        ++i;
      } else {
        auto it = v[i].begin();
        v[i-1].emplace(*it);
        u(i,-*it);
        u(i-1,*it);
        v[i].erase(it);
        --i;
      }
    }
    return sum;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n,m,q;cin>>n>>m>>q;
  T op;
  op.n=n;
  op.m=m;
  vl arr(n),brr(m),trr;
  for(auto& i: arr) cin>>i,trr.emplace_back(i);
  for(auto& i: brr) cin >> i, trr.emplace_back(i);
  sort(all(trr));
  for (auto i = 0; i < n/2; i++) op.v[0].emplace(trr[i]),op.sum+=trr[i];
  for (auto i = n/2; i < n+m-n/2; i++) op.v[1].emplace(trr[i]);
  for (auto i = 0; i < n/2; i++) op.v[2].emplace(trr[n+m-i-1]),op.sum+=trr[n+m-i-1];
  // dbg(op.sum);
  for (auto _ = 0; _ < q; _++) {
    int t,i,x;cin>>t>>i>>x;
    --i;
    ll ans = 0;
    if(t==1) {
      ans = op.op(arr[i],x);
      arr[i]=x;
    } else {
      ans = op.op(brr[i],x);
      brr[i]=x;
    }
    cout<<ans<<'\n';
  }
}

