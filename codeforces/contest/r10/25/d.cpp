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

using li = pair<ll, int>;
int t, n, m, l;
ll even,odd;
vl d1, d2;
ll inf = ll(1e15);
vector<vi> adj;


bool match(ll u, ll v) { return (v&1) == (u&1);}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  cin >> t;
  while(t--) {
    cin >> n >> m>>l;
    vl arr(l);
    for(auto& i: arr) cin >>i;
    ll sum = accumulate(all(arr), 0ll);
    ll meven=inf,modd=inf;
    for(auto& i: arr) {
      if (i&1) modd=min(modd, i);
      else meven=min(meven, i);
    }
    if (sum&1) {
      odd = sum;
      even = sum-modd;
    } else {
      even=sum;
      odd=(modd==inf)?0:(sum-modd);
    }
    adj.assign(n, vi());
    for (auto i = 0; i < m; i++) {
      int u, v; cin >> u >> v;
      --u,--v;
      adj[u].emplace_back(v);
      adj[v].emplace_back(u);
    }
    d2.assign(n, inf);
    d1.assign(n, inf);
    queue<int> qu;
    ll lev = 0;
    d1[0] = 0;
    qu.emplace(0);
    while(sz(qu)) {
      int lim = sz(qu);
      for (auto i = 0; i < lim; i++) {
        int u = qu.front(); qu.pop();
        for(auto& v: adj[u]) 
          if (lev+1<d1[v]) 
            qu.emplace(v), d1[v]=lev+1;
      }
      ++lev;
    }

    priority_queue<li, vector<li>, greater<li>> pq;
    for (auto u = 0; u < n; u++) {
      for(auto& v: adj[u]) {
        if ((d1[u]==d1[v]) and d1[u]+1 < d2[v]) {
          d2[v] = d1[u]+1;
          pq.emplace(d2[v], v);
        }
      }
    }
    while(sz(pq)) {
      auto [d, u] = pq.top(); pq.pop();
      if (d > d2[u]) continue;
      for(auto& v: adj[u]) {
        //dbg(match(d, d1[v]));
        if (match(d,d1[v]) and d+1 < d2[v])  
          d2[v] = d+1, pq.emplace(d2[v], v);

      } 
    }
    //for(auto& i: d1) cout << i <<' ';
    //cout <<'\n';
    //for(auto& i: d2) cout << i <<' ';
    //cout <<'\n';
    //dbg(odd);
    //dbg(even);
    //dbg(modd);
    string ans;
    for (auto u = 0; u < n; u++) {
      auto ev=d1[u], od=d2[u];
      if (ev&1) swap(ev, od);
      ans.push_back( (ev <= even or od <=odd )?'1':'0' );
    }
    cout << ans <<'\n';
  }
}

