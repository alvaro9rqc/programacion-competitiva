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
  //cin.tie(0)->sync_with_stdio(0);
  //cin.exceptions(cin.failbit);
  using lii = tuple<ll,int,int>;
  int n, k, x; cin >> n>>k>>x;
  ll arr[100000];
  ll off = 0;
  for (auto i = 0; i < n; i++) cin >> arr[i], off=min(off,arr[i]);
  --off;
  off=min(0ll,off);
  for (auto i = 0; i < n; i++) arr[i]-=off;
  sort(arr,arr+n);
  priority_queue<lii> pq;
  pq.emplace(0,n-1,0);
  //int p = 0;
  vl ans;
  //const ll inf=1e16;
  //vector<vl> dist(n,vl(k,inf));
  //dist[0][0]=0;
  while(sz(ans) < x) {
    auto [v, ni, ki] = pq.top();pq.pop();
    //ver si es el path
    if (ki==k) {
      ans.emplace_back(v);
      continue;
    }
    pq.emplace(v+arr[ni], ni, ki+1);
    if (ni)
        pq.emplace(v, ni-1, ki);
  }
  sort(ans.rbegin(), ans.rend());
  for(auto& i: ans) cout << i+off*k <<'\n';
  //cout <<'\n';
}

