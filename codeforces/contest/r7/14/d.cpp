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
    int n,p; cin >> n>>p;
    vl arr(n), idx(n);
    for(auto& a: arr) cin >> a;
    iota(all(idx), 0);
    vector<bool> vis(n);
    sort(all(idx), [&arr](int a, int b) {return arr[a]<arr[b];});
    int tkn = 0;
    ll ans = 0;
    for(auto& i: idx) {
      if (arr[i] >= p) break;
      //if (vis[i]) continue;
      for (auto j = i-1; j >= 0; j--) 
        if (not vis[j] and gcd(arr[i], arr[j]) == arr[i]) {
          ++tkn;
          ans+=arr[i];
          vis[j]=1;
        } else {break;}
      for (auto j = i; j < n-1; j++) 
        if (not vis[j] and gcd(arr[i], arr[j+1]) == arr[i]) {
          ++tkn;
          ans+=arr[i];
          vis[j]=1;
        } else break;
    }
    /* 
     * ERROR: no te centres en los nodos, centrate en las arístas visitadas
      */
    //dbg(ans);
    //dbg(tkn);
    cout << (ans+ll(n-1-tkn)*p) <<'\n';
  }
}

