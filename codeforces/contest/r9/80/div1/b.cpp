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

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt;cin>>tt;
  using pl = pair<ll,ll>;
  while(tt--) {
    ll n;cin>>n;
    vl val(n);
    vl tel(n);
    for(auto& i: val) cin >> i;
    for(auto& i: tel) cin >> i,--i;
    set<ll> ava;
    for (auto i = 0; i < n; i++) ava.emplace(i);

    priority_queue<pl,vector<pl>,greater<pl>> pq;
    ll inf = 1e16;
    vl dist(n,inf);
    dist[0]=0;
    pq.emplace(0,0);
    while(sz(pq)) {
      auto[du, u] = pq.top();pq.pop();
      if(du>dist[u])continue;
      ava.erase(u);
      //eli
      auto it = ava.upper_bound(tel[u]);
      if (it!=ava.begin()) {
        --it;
        // dbg(*it);
        ll v = *it;
        if (du+val[u]<dist[v])pq.emplace(du+val[u], v),dist[v]=du+val[u];
      }
      it = ava.upper_bound(u);
      if (it!=ava.begin()) {
        --it;
        ll v = *it;
        if (du<dist[v])pq.emplace(du, v),dist[v]=du;
      }
    }
    ll ps=0;
    ll ans = 0;
    // for(auto& i: dist) cerr<<i<<' ';
    // cerr<<'\n';
    for (auto i = 0; i < n; i++) {
      ps+=val[i];
      ans=max(ans, ps-dist[i]);
    }
    cout<<ans<<'\n';
  }
}

