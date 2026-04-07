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
    int n;cin>>n;
    int k;cin>>k;
    vector<int> val(n); for(auto& i: val) cin >> i;
    cin>>k;
    --k;
    int x = val[k];
    int inv=0;
    int ans = 0;
    int l = 0, r =n-1;
    // dbg(val[r]^inv);
    while(1){
      while(l<k and (val[l]^inv)==x)++l;
      while(r>k and (val[r]^inv)==x)--r;
      if((val[k]^inv)!=x or (l!=k) or r!=k) {
        ++ans;
        inv^=1;
      } else break;
    }
    cout<<ans<<'\n';
  }
}

