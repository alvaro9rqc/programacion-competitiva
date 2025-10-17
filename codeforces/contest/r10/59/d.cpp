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
  int tt; cin>>tt;
  while(tt--) {
    int n; cin >> n;
    int l=1, r=n;
    //siempre r = x
    while(l!=r) {
      int m = (l+r)/2;
      ll a,b;
      cout << format("{} {} {}", 1, l, m)<<endl;
      cin >> a ;
      cout << format("{} {} {}", 2, l, m)<<endl;
      cin >> b;
      if (a==b) {
        l=m+1;
      } else r=m;
    }
    ll a, b; 
    cout << format("{} {} {}", 1, 1, n)<<endl;
    cin >> a ;
    cout << format("{} {} {}", 2, 1, n)<<endl;
    cin >> b;
    ll nn = b - a;
    cout << format("! {} {}", l, l+nn-1)<<endl;
  }
}

