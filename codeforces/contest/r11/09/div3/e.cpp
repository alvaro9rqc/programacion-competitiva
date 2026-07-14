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
  int n,q;cin>>n>>q;
  string s;cin>>s;
  vl val(n);
  for (auto i = 1; i < n; i++) val[i]+=(s[i]==s[i-1]);
  for (auto i = 1; i < n; i++) val[i]+=val[i-1];
  auto pre=[&](int l, int r) {
    return val[r]-(l?val[l-1]:0);
  };
  for (auto _ = 0; _ < q; _++) {
    int l,r,k;cin>>l>>r>>k;
    --l,--r;
    ll x=0;
    if(r!=l){
      x = pre(l+1,r);
      x=x/2+(x&1);
    }
    cout<<(k>=x?"yes":"no")<<'\n';
  }
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

