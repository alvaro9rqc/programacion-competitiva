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
  vi arr(1<<24);
  for (auto i = 0; i < n; i++) {
    string s;cin>>s;
    int m = 0;
    for(auto& c: s) m|=(1<<(c-'a'));
    for (auto x = m; x > 0 ; x=(x-1)&m) 
      arr[x]+=1;
  }
  dbg(arr[0b11]);
  for (auto i = 0; i < 24; i++) {
    for (auto j = 0; j < (1<<24); j++) {
      if(j&(1<<i)) {
        arr[j]+=arr[j^(1<<i)] - (1<<(__builtin_popcount(
          ((1<<i)-1)&j
        )))+1;
      }
    }
  }
  dbg(arr[0b11]);
  // int x= __builtin_popcount(3);
  cout<<arr[(1<<24)-1]<<'\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tt=1;
  // cin>>tt;
  while(tt--) {
    solve();
  }
}

