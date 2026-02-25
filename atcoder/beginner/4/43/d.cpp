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
  int tt; cin >> tt;
  while(tt--) {
    int n; cin >> n;
    vi arr(n); for(auto& i: arr) cin>>i, i=n-i+1;
    ll ans = 0;
    priority_queue<ii> pq;
    vector<bool> vis(n);
    for (auto i = 0; i < sz(arr); i++) 
      pq.emplace(arr[i],i);

    //for(auto& i: arr) 
    //cout << i <<' ';
    //cout <<'\n';
    while(sz(pq)) {
      auto [r, i] = pq.top(); pq.pop();
      if (vis[i])continue;
      vis[i]=1;
      if (i+1<n and not vis[i+1]) {
        if (arr[i]>arr[i+1]+1) {
          ans+=arr[i]-(arr[i+1]+1);
          arr[i+1]=arr[i]-1;
          pq.emplace(arr[i+1],i+1);
        }
      }
      if (i-1>=0 and not vis[i-1]) {
        if (arr[i]>arr[i-1]+1) {
          ans+=arr[i]-(arr[i-1]+1);
          arr[i-1]=arr[i]-1;
          pq.emplace(arr[i-1],i-1);
        }
      }
      //raya;
    }
    //for(auto& i: arr) 
    //cout << i <<' ';
    //cout <<'\n';
    cout << ans<<'\n';
  }
}

