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
  for(auto& i: arr) cin>>i;
  for(auto& i: brr) cin>>i;
  ll d = 0;
  for (auto i = n-1; i >= 1; i--) {
    if(arr[i]+d>brr[i]) d = arr[i]+d-brr[i];
    else d = 0;
  }
  if(arr[0]+d>brr[0]){
    cout<<"no\n";
  } else 
    cout<<"yes\n";

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

