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
    int n; cin >> n;
    vi arr(n);
    ll s=0;
    for(auto& i: arr) cin >> i;
    vi ele;
    for(auto& i: arr) if (i !=0) ele.emplace_back(i), s+=i;
    ll ans = 0;
    //sort(all(ele));
    for (auto i = 1; i < sz(ele); i++) ele[i]+=ele[i-1];
    //dbg(s);
    for (auto i = sz(ele)-1; i >=0; i--) {
      if (s-(i+1)>= n-1){
        ans = i+1; 
        break;
      }
    }
    cout << ans <<'\n';
  }
}

