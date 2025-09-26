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
    int n; ll k;
    cin >> n >> k;
    vi arr(n);
    for(auto& i: arr) cin >> i;
    map<int, int> mp;
    for(auto& i: arr) ++mp[i];
    ll ans = 0;
    if ( mp[0] == 0 ) {
      if (n&1) ans=0;
      else ans = n;
    } else if (mp[0] == 1) {
      int lim = 0;
      for (auto i = 0; i <= n; i++) 
        if (not mp.count(i)){
          lim = i;
          break;
        }
      for (auto i = 0; i < n; i++) {
        if (mp[arr[i]] > 1 or arr[i]>lim) arr[i]=lim;
      }
      if (k == 1) {
        for(auto& i: arr) ans+=i;
        goto gaa;
      }
      sort(all(arr));
      mp.clear();
      for(auto& i: arr) ++mp[i];
      int nrep = 0;
      for(auto& [k,v]: mp) nrep = max(nrep, v);
      if (nrep == 1) {
        ans = n-1;
        ans = ans*(ans+1)/2;
      } else {
        for (auto i = 0; i < n+1; i++) 
          if (mp[i]>1) {
            lim = i;
            break;
          }
        ll lans = 0;
        for(auto& i: arr) if (i < lim) lans+=i;
        int d = 0;
        for (auto i = 0; i < n; i++) {
          if (arr[i]>=lim) {
            d = i; break;
          }
        }
        //for(auto& i: arr) cout << i <<' ';
        //cout <<'\n';
        //dbg(d);
        //dbg(lim);
        //dbg(lans);
        if (k%2==1) {
          ans = lans + (n-d)*lim;
        } else {
          ans = lans + (n-d)*(lim+1);
        }
        goto gaa;
      }
    } else  {
      if (k == 1) {
        int lim = 0;
        for (auto i = 0; i <= n; i++) 
          if (not mp.count(i)){
            lim = i;
            break;
          }
        for(auto& i: arr) {
          if (mp[i] == 1) ans+=i;
          else ans+=lim;
        }
      } else {
        ans = (k&1)? n:0;
      }
    }
gaa:
    cout << ans <<'\n';
  }
}


