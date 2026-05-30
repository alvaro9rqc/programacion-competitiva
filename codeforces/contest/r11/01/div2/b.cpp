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
  vl val(n); for(auto& i: val) cin >> i;  
  ll h;
  ll d=0;
  cout<<(h=val[0])<<' ';
  for (auto i = 1; i < n; i++) {
    if(h>val[i]) {
      ll a = d+(h-val[i])*i;
      ll h1 = a/(i+1)+val[i];
      ll d1 = a%(i+1);
      if(h1>h) {
        ll v= min(d,h-val[i]);
        d-=v;
      } else h=h1,d=d1;
    } else {
      d+=val[i]-h;
    }
    cout<<h<<' ';
  }
  cout<<'\n';
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

