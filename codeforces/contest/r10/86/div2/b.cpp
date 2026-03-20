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
  using pl = pair<ll,int>;
  while(tt--) {
    ll n,k,m;
    int p;
    cin>>n>>k>>p>>m;
    --p;
    vl arr(n);
    for(auto& i: arr) cin >> i;
    priority_queue<pl, vector<pl>, greater<pl>> pq;
    queue<pl> que;
    ll ene = 0;
    bool esta = 0;
    for (auto i = 0; i < k; i++) {
      if(i==p) {
        esta=1;
        continue;
      }
      pq.emplace(arr[i],i);
    }
    for (auto i = k; i < n; i++) que.emplace(arr[i],i);
    ll ans = 0;
    while(1) {
      //tomo
      ll et = 0;
      int idx = 0;
      if(esta) et=arr[p],idx=p,esta=0;
      else {
        et=pq.top().first;
        idx=pq.top().second;
        pq.pop();
      }
      if (ene+et>m) break;
      ans+=idx==p;
      ene+=et;
      que.emplace(et,idx);
      auto [ne, ni] = que.front(); que.pop();
      if(ni==p) esta=1;
      else 
        pq.emplace(ne,ni);
    }
    cout<<ans<<'\n';
  }
}

