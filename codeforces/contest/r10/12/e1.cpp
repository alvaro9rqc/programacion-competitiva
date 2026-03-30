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
  while(tt--) {
    int n,k;cin>>n>>k;
    vl arr(n),brr(n);
    for(auto& i: arr) cin >> i;
    for(auto& i: brr) cin >> i;
    ll s  = 0;
    ll ans = 0;
    for (auto i = 0; i < n; i++) arr.emplace_back(arr[i]);
    for (auto i = 0; i < n; i++) brr.emplace_back(brr[i]);
    for (auto i = 0,j=0; i < n; ) {
      // dbg(i);
      // dbg(j);
      // dbg(s);
      if(s<0 or i==j){
        s+=brr[j]-arr[j];
        ++j;
      } else {
        ll xd = j-i;
        ans=max(ans,xd);
        s-=brr[i]-arr[i];
        ++i;
      }
    }
    cout<<ans<<'\n';
  }
}

