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
    int n,l,r; cin >> n>>l>>r;
    --l,--r;
    vi arr(n);
    iota(all(arr), 1);
    //for(auto& i: arr) cout << " : "<<i<<',';
    l?(arr[r]=arr[l-1]):arr[r]=0;
    cout << arr[0]<<' ';
    for (auto i = 1; i < n; i++) 
      cout << (arr[i]^arr[i-1])<<' ';
    cout <<'\n';
  }
}


