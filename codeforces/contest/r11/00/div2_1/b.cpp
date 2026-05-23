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
  vl arr(n), brr(n);
  for(auto& i: arr) cin >> i;
  for(auto& i: brr) cin >> i;
  for (auto i = 0; i < n; i++) {
    if(brr[i]<arr[i])swap(brr[i],arr[i]);
  }
  ll ans = 0;
  for(auto& b: brr) ans+=b;
  ll ma = 0;
  for(auto& i: arr) ma=max(ma,i);
  cout<<ans+ma<<'\n';
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

