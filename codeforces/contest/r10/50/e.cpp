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
    int n, k; cin >> n >> k;
    vi arr(n);
    for(auto& i: arr) cin >> i;
    bool can = 1;
    vi mapa(n+1);
    for(auto& i: arr) ++mapa[i];
    for(auto& i: mapa) if (i%k!=0)can=0;
    if ( n%k or ! can){
      cout <<0<<'\n';
      continue;
    }
    for(auto& i: mapa) i/=k;
    ll ans = 0;
    vi count(n+1);
    ll i=0, j=0;
    while(1) {
      while(j<n and count[arr[j]]<mapa[arr[j]]){
        ++count[arr[j]], ++j;
        ans+=j-i;
      }
      //ans+= (j -i)*(j-i+1)/2;
      if (j==n) break;
      while(count[arr[j]]+1>mapa[arr[j]])--count[arr[i]],++i;
    }
    cout << ans<<'\n';
  }
}

