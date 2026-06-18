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

void solve() {
  int n;cin>>n;
  vl arr(n),brr(n);
  for(auto& i: arr) cin >> i;
  for(auto& i: brr) cin >> i;
  bool can = 1;
  for (auto i = 0; i < n; i++) {
    auto a = arr[i];
    for (auto j = 0; j < n; j++) {
      if(brr[j]!=-1 and a<=brr[j]) {
        brr[j]=-1;
        arr[i]=j;
        a=-1;
        break;
      }
    }
    if(a!=-1) {can=0;break;}
  }
  if(not can) {
    cout<<"-1\n";
    return;
  }
  ll ans = 0;
  for (auto i = 0; i < n; i++) {
    auto a = arr[i];
    for (auto j = i+1; j < n; j++) 
      if(a>arr[j])++ans;
  }
  cout<<ans<<'\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt=1;
  cin>>tt;
  while(tt--) {
    solve();
  }
}

