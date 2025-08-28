#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
#define endl '\n'
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
    ll n,k; cin >> n >> k;
    vl a(n); 
    for(auto& i: a) cin >> i;
    if(k%2==0) {
      for(auto& ei: a) {
        ll r = ei%(k+1);
        ei+=r*k;
      }
      for(auto& ei: a) cout << ei <<' ';
      cout << '\n';
    } else {
      for(auto& ei: a) {
        cout << (ei%2?ei+k:ei) <<' ';
      }
      cout << '\n';
    }
  }
}


